#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const long long M = 1000000007;

int n;

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

long long f[N * 2];

long long zug(long long n, long long k)
{
    return (((f[n] * ast(f[k], M - 2)) % M) * ast(f[n - k], M - 2)) % M;
}

int main()
{
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n + n; ++i)
        f[i] = (f[i - 1] * i) % M;
    long long ans = 0;
    for (int i = n - 1; i <= n + n - 2; ++i)
        ans = (ans + zug(i, i - (n - 1))) % M;
    cout << (ans + ans - n + M) % M << endl;
    return 0;
}