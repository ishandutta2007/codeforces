#include <bits/stdc++.h>

using namespace std;

int k[61];
long long MAXN = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 1;
long long MAXM = 1000ll * 1000 * 1000;

long long fast_pow(long long a, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return a;
    long long b = fast_pow(a, p / 2);
    if (b > MAXM)
        return MAXN;
    if (p % 2 == 0)
    {
        return b * b;
    }
    else
    {
        b *= b;
        if (a > MAXN / b)
            return MAXN;
        return b * a;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 2; i <= 60; i++)
    {
        int cnt = 0;
        int u = i;
        for (int e = 2; e * e <= u; e++)
        {
            if (u % e == 0)
            {
                u /= e;
                cnt++;
            }
            if (u % e == 0)
            {
                cnt = -1;
                break;
            }
        }
        if (cnt != -1)
        {
            if (cnt % 2 == 0)
                k[i] = 1;
            else
                k[i] = -1;
        }
    }
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        long long n;
        cin >> n;
        long long cur = 0;
        for (int e = 2; e <= 60; e++)
        {
            if (k[e] == 0)
                continue;
            long long a = floor(pow(n, 1.0 / e));
            while (fast_pow(a, e) > n)
                a--;
            while (fast_pow(a + 1, e) <= n)
                a++;
            cur += k[e] * (a - 1);
        }
        cout << n - 1 - cur << "\n";
    }
}