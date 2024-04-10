#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 6000;
const int MAXF = MAXN * 3 / 2;

int f[MAXF];
int p[MAXF];
int k, n, m;
int ans[MAXN];

int prime(int x)
{
    if (x < 2) return false;
    for (int i = 0; i < k && p[i] * p[i] <= x; i++)
        if (x % p[i] == 0) return false;
    return true;
}

int main()
{
/*
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//*/
    for (int i = 2; i < MAXF; i++)
        if (f[i] == false)
        {
            p[k++] = i;
            int j = i * i;
            while (j < MAXF)
            {
                f[j] = true;
                j += i;
            }
        }
        
    scanf("%d", &n);
    
//    for (int n = 2; n <= 100; n++) {
    
    memset(ans, 0, sizeof(ans));
    m = (1 + n) * n / 2;
    
    if (prime(m))
    {
        for (int i = 1; i <= n; i++)
            ans[i] = 1;
    }
    else
    {
        if (m % 2 == 1 && !prime(m - 2))
        {
            ans[3] = 3;
            m -= 3;
        }
    
        if (m % 2 == 0 || prime(m - 2))
        {
            int s;
            if (prime(m - 2))
            {
                s = m - 2;
                ans[2] = 2;
            }
            else
            {
                for (s = 1; s <= m; s++)
                    if (prime(s) && prime(m - s)) break;
            }
            for (int i = n; i >= 1; i--)
                if (ans[i] == 0)
                {
                    ans[i] = 1 + (s < i);
                    if (s >= i) s -= i;
                }
        }
    }
    
    for (int i = 1; i < n; i++)
        printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
//    }
    return 0;
}