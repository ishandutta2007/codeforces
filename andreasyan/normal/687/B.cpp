#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

long long lca(long long x, long long y)
{
    return x / gcd(x, y) * y;
}

int n, k;
int a[N];

int t[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        if (!i || a[i] != a[i - 1])
        {
            int x = a[i];
            for (int j = 2; j * j <= x; ++j)
            {
                if (x % j == 0)
                {
                    int q = 0;
                    while (x % j == 0)
                    {
                        ++q;
                        x /= j;
                    }
                    t[j] = max(t[j], q);
                }
            }
            if (x > 1)
            {
                t[x] = max(t[x], 1);
            }
        }
    }

    bool z = true;
    for (int j = 2; j * j <= k; ++j)
    {
        if (k % j == 0)
        {
            int q = 0;
            while (k % j == 0)
            {
                ++q;
                k /= j;
            }
            if (t[j] < q)
            {
                z = false;
            }
        }
    }
    if (k > 1)
    {
        if (!t[k])
            z = false;
    }

    if (z)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}