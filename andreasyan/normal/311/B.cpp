#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005, P = 102;
const long long INF = 1000000009000000009;
struct ban
{
    long long b, k;
    ban(){}
    ban(long long b, long long k)
    {
        this->b = b;
        this->k = k;
    }
    long long yat(long long x)
    {
        return b + k * x;
    }
};

long double hat(const ban& t1, const ban& t2)
{
    return (t2.b - t1.b) / (long double)(t1.k - t2.k);
}

int n, m, q;
int d[N];

long long u[N];
long long p[N];

long long dp[N];

void solv()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 2; i <= n; ++i)
        scanf("%d", &d[i]);
    for (int i = 1; i <= n; ++i)
        d[i] += d[i - 1];
    for (int i = 1; i <= m; ++i)
    {
        int x, t;
        scanf("%d%d", &x, &t);
        u[i] = t - d[x];
    }
    sort(u + 1, u + m + 1);
    for (int i = 1; i <= m; ++i)
        p[i] = p[i - 1] + u[i];
    for (int i = 1; i <= m; ++i)
        dp[i] = INF;
    long long ans = INF;
    for (int ii = 0; ii < q; ++ii)
    {
        vector<ban> v;
        vector<long double> h;
        for (int i = 0; i <= m; ++i)
        {
            if (dp[i] == INF)
                continue;
            ban t = ban(dp[i] + p[i], -i);
            while (v.size() >= 2 && h.back() >= hat(t, v.back()))
            {
                v.pop_back();
                h.pop_back();
            }
            if (!v.empty())
                h.push_back(hat(t, v.back()));
            v.push_back(t);
        }
        int j = 0;
        for (int i = 1; i <= m; ++i)
        {
            while (j < h.size() && u[i] > h[j])
                ++j;
            dp[i] = i * u[i] - p[i] + v[j].yat(u[i]);
        }
        ans = min(ans, dp[m]);
    }
    printf("%lld\n", ans);
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