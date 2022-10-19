#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 102, M = 1000000007;
struct ban
{
    int n, m;
    int a[N][N];
    ban();
    ban(int n, int m)
    {
        this->n = n;
        this->m = m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] = 0;
    }
};
ban operator*(const ban& a, const ban& b)
{
    ban res(a.n, b.m);
    for (int i = 0; i < a.n; ++i)
    {
        for (int j = 0; j < b.m; ++j)
        {
            for (int k = 0; k < a.m; ++k)
            {
                res.a[i][j] += ((1LL * a.a[i][k] * b.a[k][j]) % M);
                res.a[i][j] %= M;
            }
        }
    }
    return res;
}

int n, k;

ban ast(ban x, int n)
{
    if (n == 1)
        return x;
    if (n == 2)
        return x * x;
    if (n % 2 == 0)
    {
        ban y = ast(x, n / 2);
        return y * y;
    }
    else
    {
        ban y = ast(x, n - 1);
        return x * y;
    }
}

int32_t main()
{
    cin >> n >> k;
    if (k > n)
    {
        cout << 1 << endl;
        return 0;
    }
    if (k == n)
    {
        cout << 2 << endl;
        return 0;
    }
    ban y(1, k);
    for (int j = 0; j < k; ++j)
        y.a[0][j] = 1;
    ban x(k, k);
    for (int i = 0; i < k; ++i)
    {
        if (i < k - 1)
        {
            x.a[i][i + 1] = 1;
        }
        else
        {
            x.a[i][0] = 1;
            x.a[i][i] = 1;
        }
    }
    ban t = ast(x, n - (k - 1));
    ban ans = y * t;
    cout << ans.a[0][k - 1] << endl;
    return 0;
}