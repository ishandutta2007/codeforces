#include <bits/stdc++.h>
using namespace std;
const int N = 102, M = 1000000007;

int qq, b, k, n;

struct ban
{
    int a[N][N] = {};
};
ban operator*(const ban& a, const ban& b)
{
    ban res;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                res.a[i][j] += (a.a[i][k] * 1LL * b.a[k][j]) % M;
                res.a[i][j] %= M;
            }
        }
    }
    return res;
}

ban ast(ban x, int nn)
{
    ban ans;
    for (int i = 0; i < n; ++i)
        ans.a[i][i] = 1;
    while (nn)
    {
        if (nn % 2 == 1)
            ans = ans * x;
        x = x * x;
        nn /= 2;
    }
    return ans;
}

int q[10];

int main()
{
    scanf("%d%d%d%d", &qq, &b, &k, &n);
    while (qq--)
    {
        int x;
        scanf("%d", &x);
        q[x]++;
    }
    ban x;
    for (int i = 0; i < n; ++i)
    {
        for (int k = 1; k <= 9; ++k)
        {
            x.a[i][(i * 10 + k) % n] += q[k];
        }
    }
    x = ast(x, b);
    cout << x.a[0][k] << endl;
    return 0;
}