#include <bits/stdc++.h>
using namespace std;

char arr[100010];
int nex[26][100010];
int mem[252][252][252];
int str[4][252];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, q, i, j, k;
    scanf("%d%d%s", &n, &q, arr + 1);

    for(i = 0; i < 26; i++)
    {
        int p = n + 1;
        nex[i][p] = p;
        for(j = n; j >= 0; j--)
        {
            nex[i][j] = p;
            if(arr[j] == 'a' + i)
                p = j;
        }
    }

    int s1 = 0, s2 = 0, s3 = 0;
    for(int qi = 0; qi < q; qi++)
    {
        char t, c;
        int x;
        scanf(" %c%d", &t, &x);
        if(t == '+')
        {
            scanf(" %c", &c);
            int ci = c - 'a';

            if(x == 1)
            {
                str[x][s1 + 1] = ci;
                for(j = 0; j <= s2; j++)
                {
                    for(k = 0; k <= s3; k++)
                    {
                        int &cur = mem[s1 + 1][j][k];
                        cur = nex[ci][mem[s1][j][k]];
                        if(j)
                            cur = min(cur, nex[str[2][j]][mem[s1 + 1][j - 1][k]]);
                        if(k)
                            cur = min(cur, nex[str[3][k]][mem[s1 + 1][j][k - 1]]);
                    }
                }
                s1++;
            }
            else if(x == 2)
            {
                str[x][s2 + 1] = ci;
                for(i = 0; i <= s1; i++)
                {
                    for(k = 0; k <= s3; k++)
                    {
                        int &cur = mem[i][s2 + 1][k];
                        cur = nex[ci][mem[i][s2][k]];
                        if(i)
                            cur = min(cur, nex[str[1][i]][mem[i - 1][s2 + 1][k]]);
                        if(k)
                            cur = min(cur, nex[str[3][k]][mem[i][s2 + 1][k - 1]]);
                    }
                }
                s2++;
            }
            else
            {
                str[x][s3 + 1] = ci;
                for(i = 0; i <= s1; i++)
                {
                    for(j = 0; j <= s2; j++)
                    {
                        int &cur = mem[i][j][s3 + 1];
                        cur = nex[ci][mem[i][j][s3]];
                        if(i)
                            cur = min(cur, nex[str[1][i]][mem[i - 1][j][s3 + 1]]);
                        if(j)
                            cur = min(cur, nex[str[2][j]][mem[i][j - 1][s3 + 1]]);
                    }
                }
                s3++;
            }
        }
        else
        {
            if(x == 1)
                s1--;
            else if(x == 2)
                s2--;
            else
                s3--;
        }

        if(mem[s1][s2][s3] > n)
            puts("NO");
        else
            puts("YES");
    }

    return 0;
}