#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 500005;
pair<int, int> M = m_p(944353633, 528902189);

long long gcd(long long x, long long y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

bool isprime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

pair<int, int> ast[N];

pair<int, int> sum(const pair<int, int>& a, const pair<int, int> & b)
{
    return m_p((a.first + b.first) % M.first, (a.second + b.second) % M.second);
}

void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i < N; ++i)
        ast[i] = sum(ast[i - 1], ast[i - 1]);
}

int n, m;
long long a[N];

pair<pair<int, int>, int> u[N];

void solv()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", &a[i]);
    for (int i = 1; i <= n; ++i)
    {
        u[i].first = m_p(0, 0);
        u[i].second = i;
    }
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        u[y].first = sum(u[y].first, ast[x]);
    }
    sort(u + 1, u + n + 1);
    long long ans = 0;
    long long s = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (u[i].first == m_p(0, 0))
            continue;
        if (u[i].first != u[i - 1].first)
        {
            ans = gcd(ans, s);
            s = a[u[i].second];
        }
        else
        {
            s += a[u[i].second];
        }
    }
    ans = gcd(ans, s);
    printf("%lld\n", ans);
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    pre();
    int tt;
    scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}