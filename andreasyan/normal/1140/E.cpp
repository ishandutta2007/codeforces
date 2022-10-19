#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const long long M = 998244353;
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
        return (x * y) % M;
    }
}

int n, k;
int a[N];

long long l[N][2];
long long ans0[N], ans1[N], ansh[N], ans[N];
void pre()
{
    ans0[0] = 1;
    ans0[1] = k;
    for (int i = 2; i <= n; ++i)
        ans0[i] = (ans0[i - 1] * (k - 1)) % M;

    l[0][1] = 1;
    l[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        l[i][1] = l[i - 1][0];
        l[i][0] = ((l[i - 1][1] * (k - 1)) % M + (l[i - 1][0] * (k - 2)) % M) % M;
    }

    for (int i = 0; i <= n; ++i)
        ans1[i] = (l[i][0] + l[i][1]) % M;

    for (int i = 0; i <= n; ++i)
        ansh[i] = l[i][0];

    for (int i = 0; i <= n; ++i)
    {
        ans[i] = (l[i][1] + ((((l[i][0] * ast(k - 1, M - 2)) % M) * (k - 2)) % M)) % M;
    }
}

int m;
int b[N];
int solv()
{
    long long res = 1;
    int i = 0;
    for (int j = 1; j <= m; ++j)
    {
        if (b[j] != -1)
        {
            if (!i)
                res *= ans1[j - 1];
            else
            {
                if (b[i] == b[j])
                {
                    res *= ansh[j - i - 1];
                }
                else
                {
                    res *= ans[j - i - 1];
                }
            }
            i = j;
        }
        res %= M;
    }
    if (!i)
        res *= ans0[m];
    else
        res *= ans1[m - i];
    res %= M;
    return res;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    pre();
    for (int i = 1; i <= n; i += 2)
        b[++m] = a[i];
    long long res1 = solv();

    m = 0;
    for (int i = 2; i <= n; i += 2)
        b[++m] = a[i];
    long long res2 = solv();

    cout << (res1 * res2) % M << endl;
    return 0;
}