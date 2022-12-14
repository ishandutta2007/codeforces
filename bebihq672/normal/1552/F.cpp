#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int x[202020], y[202020], s[202020];

int f[202020], g[202020];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d%d%d", &x[i], &y[i], &s[i]);
    
    f[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        int l = 1, r = i;
        while(l < r)
        {
            int m = (l + r) / 2;
            if(x[m] < y[i])
                l = m + 1;
            else
                r = m;
        }
        f[i] = (x[i] - y[i]) % mod;
        f[i] += (g[i - 1] - g[l - 1] + mod) % mod;
        if(f[i] >= mod)
            f[i] -= mod;
        g[i] = f[i] + g[i - 1];
        if(g[i] >= mod)
            g[i] -= mod;
    }
    int ans = (x[n] + 1) % mod;
    for(int i = 1; i <= n; i++)
    if(s[i] == 1)
    {
        ans += f[i];
        if(ans >= mod)
            ans -= mod;
    }
    printf("%d\n", ans);
    return 0;
}