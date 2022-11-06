#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
char ori[200010];
int arr[200010];
int mem[200010][4];

void solve()
{
    int n;
    scanf("%d%s", &n, ori);

    for(int i = 0; i < n; i++)
        arr[i] = (ori[i] == 'L');
    arr[n] = arr[0];
    arr[n + 1] = arr[1];

    int res = INF;
    for(int b = 0; b < 4; b++)
    {
        int d0 = b % 2;
        int d1 = b / 2;
        for(int d = 0; d < 4; d++)
        {
            if(d == b)
                mem[1][d] = (int)(d0 != arr[0]) + (int)(d1 != arr[1]);
            else
                mem[1][d] = INF;
        }

        for(int i = 2; i <= n + 1; i++)
        {
            for(int d = 0; d < 4; d++)
            {
                mem[i][d] = INF;
                int t = (d / 2 != arr[i]);
                for(int p = 0; p < 2; p++)
                {
                    if(d == 0 && p == 0 || d == 3 && p == 1)
                        continue;

                    mem[i][d] = min(mem[i][d], t + mem[i - 1][d % 2 * 2 + p]);
                }
            }
        }

        res = min(res, mem[n + 1][b] - mem[1][b]);
    }
    printf("%d\n", res);
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
        solve();

    return 0;
}