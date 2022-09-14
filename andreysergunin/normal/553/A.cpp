#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10500;
const int p = 1e9 + 7;

long long f(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long t = f(a, b / 2);
    long long ans = t * t % p;
    if (b % 2 == 1)
        ans = ans * a % p;
    return ans;
}

long long c(long long n, long long k)
{
    long long u = 1, v = 1;
    for (long long i = n - k + 1; i <= n; i++)
        u = u * i % p;
    for (long long i = 1; i <= k; i++)
        v = v * i % p;
    long long ans = (u * f(v, p - 2)) % p;
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int k;
    long long a[MAXN];
    cin >> k;
    for (int i = 0; i < k; i++)
        cin >> a[i];
    long long ans = 1;
    long long n = 0;
    for (long long i = 0; i < k; i++)
    {
        ans = (ans * c(n + a[i] - 1, a[i] - 1)) % p;
        n += a[i];
    }
    cout << ans << endl;
}