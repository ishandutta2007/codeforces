#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 105;
const int M = 998244353;

int gcdd(int a, int b, int& x, int& y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1_;
    int g = gcdd(b % a, a, x1, y1_);
    x = y1_ - (b / a) * x1;
    y = x1;
    return g;
}

struct ban
{
    int n;
    int a[N][N];
    ban()
    {
        n = 0;
        memset(a, 0, sizeof a);
    }
};
ban operator*(const ban& a, const ban& b)
{
    ban res;
    res.n = a.n;
    for (int i = 1; i <= a.n; ++i)
    {
        for (int j = 1; j <= a.n; ++j)
        {
            for (int k = 1; k <= a.n; ++k)
            {
                res.a[i][j] = (res.a[i][j] + (a.a[i][k] * 1LL * b.a[k][j]) % (M - 1)) % (M - 1);
            }
        }
    }
    return res;
}

ban ast(ban x, int n)
{
    ban res;
    res.n = x.n;
    for (int i = 1; i <= x.n; ++i)
        res.a[i][i] = 1;
    while (n)
    {
        if (n % 2 == 1)
            res = res * x;
        x = x * x;
        n /= 2;
    }
    return res;
}

int ast(int x, int n)
{
    int res = 1;
    while (n)
    {
        if (n % 2 == 1)
            res = (res * 1LL * x) % M;
        x = (x * 1LL * x) % M;
        n /= 2;
    }
    return res;
}

int b[N];

void solv()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &b[i]);
    ban x;
    x.n = n;
    for (int i = 1; i < n; ++i)
        x.a[i][i + 1] = 1;
    for (int i = 1; i <= n; ++i)
        x.a[n][i] = b[n - i + 1];
    int k, m;
    scanf("%d%d", &k, &m);
    x = ast(x, k - n);
    int u = x.a[n][n];
    int s = sqrt(M);
    int y = -1;
    for (int i = s * s; i < M; ++i)
    {
        if (ast(3, i) == m)
        {
            y = i;
            break;
        }
    }
    map<int, int> mp;
    for (int q = 0; q < s; ++q)
        mp[ast(3, q * s)] = q;
    for (int t = 0; t < s; ++t)
    {
        if (mp.find((m * 1LL * ast(ast(3, t), M - 2)) % M) != mp.end())
        {
            y = mp[(m * 1LL * ast(ast(3, t), M - 2)) % M] * s + t;
        }
    }
    assert(y != -1);
    int ans, anst;
    int g = gcdd(y, u, ans, anst);
    y /= g;
    u /= g;
    g = gcdd(u, M - 1, ans, anst);
    if (g != 1)
    {
        printf("-1\n");
        return;
    }
    ans = (ans % (M - 1) + (M - 1)) % (M - 1);
    ans = (ans * 1LL * y) % (M - 1);
    printf("%d\n", ast(3, ans));
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}