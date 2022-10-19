#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n, m;
long long a[N];
long long b[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    long long t = a[2] - a[1];
    for (int i = 2; i <= n; ++i)
    {
        t = gcd(t, a[i] - a[i - 1]);
    }

    for (int i = 1; i <= m; ++i)
    {
        if (t % b[i] == 0)
        {
            cout << "YES" << endl;
            cout << a[1] << ' ' << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}