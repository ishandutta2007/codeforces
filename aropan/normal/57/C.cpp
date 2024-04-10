#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;


const int MAXN = 100001;
const int MAXF = 2 * MAXN + 1;
const int MOD = 1000000007;

bool f[MAXF];
int p[MAXF], a[MAXF];
int n, m;


int modify(int X, int D)
{
    for (int i = 0; i < m; i++)
    {
        int x = X;
        while (x /= p[i])
            a[i] += D * x;
    }
    return 0;
}

int C(int n, int m)
{
    modify(n, 1);
    modify(m, -1);
    modify(n - m, -1);
    return 0;
}


long long power(int n, int base)
{
    if (n == 0) return 1LL;
    
    long long y = power(n / 2, base);
    y = y * y % MOD;
    if (n & 1) y = y * base % MOD;
    return y;
}

int main()
{
/*
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
//*/
    m = 0;
    for (int i = 2; i < MAXF; i++)
        if  (f[i] == false)
        {
            p[m++] = i;
            if (i > MAXF / i) continue;
            int j = i * i;
            while (j < MAXF)
            {
                f[j] = true;
                j += i;
            }
        }
        
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    C(2 * n - 1, n - 1);
    
    
    long long ans = 1;
    for (int i = 0; i < m; i++)
        ans = ans * power(a[i], p[i]) % MOD;
        
    ans = ans * 2 % MOD;
    ans = (ans - n + MOD) % MOD;
    cout << ans << endl;
    return 0;
}