#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int pow2[2010];

char arr[2010];
int mem[2010][2010];
int sum[2010][2010];

int cnt[2010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;
    scanf("%s", arr + 1);
    n = strlen(arr + 1);

    pow2[0] = 1;
    for(int i = 1; i <= n; i++)
        pow2[i] = 2 * pow2[i - 1] % mod;

    for(int i = 1; i <= n; i++)
        cnt[i] = cnt[i - 1] + (arr[i] == '?' ? 1 : 0);

    for(int l = 1; l <= n; l++)
    {
        for(int i = 1; i + l - 1 <= n; i++)
        {
            int j = i + l - 1;

            if(l == 1)
            {
                mem[i][j] = 0;
                if(arr[i] != ')')
                    sum[i][j] = 1;
            }
            else
            {
                if(arr[j] == '(')
                    mem[i][j] = mem[i][j - 1];
                else
                {
                    mem[i][j] = sum[i][j - 1];

                    if(arr[j] == '?')
                        mem[i][j] = (mem[i][j - 1] + mem[i][j]) % mod;
                }
                if(arr[i] == ')')
                    sum[i][j] = sum[i + 1][j];
                else
                {
                    sum[i][j] = (mem[i + 1][j] + pow2[cnt[j] - cnt[i]]) % mod;
                    if(arr[i] == '?')
                        sum[i][j] = (sum[i][j] + sum[i + 1][j]) % mod;
                }
            }
        }
    }

    printf("%d\n", mem[1][n]);
    return 0;
}