#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <ctime>

using namespace std;

const int num[10][7] = 
{
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};


const int MAXN = 300001;

int f[10][10];
int a[MAXN];
int *b[MAXN];
char s[MAXN];
int res, curr;
int n, k;


int change(int i, int x)
{
    if (i < n) change(i + n, x);

    curr -= f[a[i]][*b[i]];
    a[i] = x;
    curr += f[a[i]][*b[i]];
    return 0;
}



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 7; k++)
                if (num[i][k] && num[i][k] == num[j][k])
                    f[i][j]++;

    gets(s);
    k = strlen(s);
    for (int i = 0; i < k; i++)
        a[i] = s[i] - '0';
    n = k / 2;


    for (int i = 0; i < n; i++)
    {
        b[i] = &a[i + n];
        b[i + n] = &a[i];
    }


    for (int i = 0; i < n; i++)
        res += f[a[i]][*b[i]];
    curr = res;

/*
    for (int i = 0; i < 10; i++)
    {
        printf("\n%d:\n", i);
        printf("0%d0\n", num[i][0]);
        printf("%d0%d\n", num[i][5], num[i][1]);
        printf("0%d0\n", num[i][6]);
        printf("%d0%d\n", num[i][4], num[i][2]);
        printf("0%d0\n", num[i][3]);
    }
    return 0;
//*/

    for (int i = k - 1; i >= 0; i--)
    {
        bool flag = false;
        for (int j = a[i] + 1; j < 10; j++)
        {
            change(i, j);
            if (curr > res)
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            for (int j = i + 1; j < k; j++)
                for (int x = 0; x < 10; x++)
                {
                    change(j, x);
                    if (curr > res)
                        break;

                }
            for (int j = 0; j < k; j++)
                printf("%d", a[j]);
            printf("\n");
            return 0;
        }
        change(i, i < n? 8 : *b[i]);
    }

    puts("-1");
    fprintf(stderr, "Time of execution: %.3lf sec.\n", (double)clock()/CLOCKS_PER_SEC);
    return 0;
}