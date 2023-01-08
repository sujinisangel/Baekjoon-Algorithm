#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int row, col;
    char** arr;
    char filter_1[8][8] = {
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'}};
    char filter_2[8][8] = {
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'},
        {'B','W','B','W','B','W','B','W'},
        {'W','B','W','B','W','B','W','B'}};
    int i, j;
    int min = 2500;
    int cnt_1 = 0;
    int cnt_2 = 0;

    
    scanf("%d %d", &row, &col);

    arr = (char**)malloc(sizeof(char*) * row);
    for (i = 0; i < row; i++)
    {
        arr[i] = (char*)malloc(sizeof(char) * (col + 1));
    }

    for (i = 0; i < row; i++)
    {
        {
            scanf("%s", arr[i]);
        }
    }
    
    // 경우의 수는 (col-8+1)*(row-8+1)

    for (j = 0; j < row - 7; j++)
    {
        for (i = 0; i < col - 7; i++)
        {
            cnt_1 = 0; cnt_2 = 0;
            for (int k = 0; k < 8; k++)
            {
                if (arr[k + j][0 + i] != filter_1[k][0]) cnt_1++;
                if (arr[k + j][1 + i] != filter_1[k][1]) cnt_1++;
                if (arr[k + j][2 + i] != filter_1[k][2]) cnt_1++;
                if (arr[k + j][3 + i] != filter_1[k][3]) cnt_1++;
                if (arr[k + j][4 + i] != filter_1[k][4]) cnt_1++;
                if (arr[k + j][5 + i] != filter_1[k][5]) cnt_1++;
                if (arr[k + j][6 + i] != filter_1[k][6]) cnt_1++;
                if (arr[k + j][7 + i] != filter_1[k][7]) cnt_1++;

                if (arr[k + j][0 + i] != filter_2[k][0]) cnt_2++;
                if (arr[k + j][1 + i] != filter_2[k][1]) cnt_2++;
                if (arr[k + j][2 + i] != filter_2[k][2]) cnt_2++;
                if (arr[k + j][3 + i] != filter_2[k][3]) cnt_2++;
                if (arr[k + j][4 + i] != filter_2[k][4]) cnt_2++;
                if (arr[k + j][5 + i] != filter_2[k][5]) cnt_2++;
                if (arr[k + j][6 + i] != filter_2[k][6]) cnt_2++;
                if (arr[k + j][7 + i] != filter_2[k][7]) cnt_2++;
            }

            if (cnt_1 < min)
            {
                min = cnt_1;
            }
            if (cnt_2 < min)
            {
                min = cnt_2;
            }
        }
    }


    printf("%d\n", min);


    for (i = 0; i < row; i++)
    {
        free(arr[i]);
    }
    free(arr);
}