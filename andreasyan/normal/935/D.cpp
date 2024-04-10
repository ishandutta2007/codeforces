#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long M = 1000000007;
long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}
long long ast(long long x, long long n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
    {
        long long y = ast(x, n / 2);
        return (y * y) % M;
    }
    else
    {
        long long y = ast(x, n - 1);
        return (y * x) % M;
    }
}

int n, m;
int a[N], b[N];

int s[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    for (int i = n; i >= 1; --i)
    {
        s[i] = s[i + 1];
        if (a[i] == 0)
            s[i]++;
        if (b[i] == 0)
            s[i]++;
    }

    long long ans = 0;

    long long h = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (!a[i] && b[i])
        {
            ans += (h * (((m - b[i]) * ast(m, s[i + 1])) % M));
            ans %= M;
        }
        else if (a[i] && !b[i])
        {
            ans += (h * (((a[i] - 1) * ast(m, s[i + 1])) % M));
            ans %= M;
        }
        else if (!a[i] && !b[i])
        {
            ans += (h * ((((m * 1LL * (m - 1) / 2) % M) * ast(m, s[i + 1])) % M));
            ans %= M;
            h = (h * m) % M;
        }
        else
        {
            if (a[i] == b[i])
                continue;
            if (a[i] > b[i])
            {
                ans += (h * (ast(m, s[i + 1])));
                ans %= M;
            }
            break;
        }
    }

    long long ansb = ast(m, s[1]);
    cout << (ans * ast(ansb, M - 2)) % M << endl;
    return 0;
}