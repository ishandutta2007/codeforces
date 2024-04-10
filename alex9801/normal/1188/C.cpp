#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int arr[1010];
int cnt[1010];
int mem[1010][1010];

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    
    int n, k, i, j;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr, arr + n);

    int t = 1;
    cnt[0] = 1;
    for(i = 1; i < n; i++)
    {
        if(arr[i] == arr[t - 1])
            cnt[t - 1]++;
        else
        {
            arr[t] = arr[i];
            cnt[t] = 1;
            t++;
        }
    }

    n = t;

    if(k > n)
    {
        puts("0");
        return 0;
    }

    for(i = 0; i < n; i++)
        mem[1][i] = cnt[i];

    int res = 0;
    int pv = 0;
    for(int d = 1; ; d++)
    {
        if(d * (k - 1) > arr[n - 1] - arr[0])
        {
            res = (res + 1LL * pv * (d - 1)) % mod;
            break;
        }

        for(i = 2; i <= k; i++)
        {
            int s = 0;
            int p = i - 2;
            for(j = i - 1; j < n; j++)
            {
                while(arr[j] - arr[p] >= d)
                    s = (s + mem[i - 1][p++]) % mod;

                mem[i][j] = 1LL * s * cnt[j] % mod;
            }
        }

        int c = 0;
        for(i = k - 1; i < n; i++)
            c = (c + mem[k][i]) % mod;

        res = (res + 1LL * (pv - c + mod) * (d - 1)) % mod;
        pv = c;
    }

    printf("%d\n", res);
    return 0;
}