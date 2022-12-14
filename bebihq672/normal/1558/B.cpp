#include<bits/stdc++.h>
using namespace std;

int f[10101010], g[10101010], h[10101010];

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);

    f[1] = 1;
    g[1] = 1;
    for(int i = 1; i <= n; i++)
    {
        if(i > 1)
        {
            h[i] += h[i - 1];

            if(h[i] >= p)
                h[i] -= p;
            
            f[i] = h[i];

            f[i] += g[i - 1];
            if(f[i] >= p)
                f[i] -= p;
            g[i] = g[i - 1] + f[i];
            if(g[i] >= p)
                g[i] -= p;
        }

        
        for(int j = i + i; j <= n; j += i)
        {
            h[j] += f[i];
            if(h[j] >= p)
                h[j] -= p;
            h[j + j / i] -= f[i];
            if(h[j + j / i] < 0)
                h[j + j / i] += p;
        }
    }
    printf("%d\n", f[n]);
    return 0;
}