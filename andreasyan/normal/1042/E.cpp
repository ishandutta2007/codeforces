#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 1003;
const long long M = 998244353;

long long ast(long long x, long long n)
{
    long long ans = 1;
    while (n)
    {
        if (n % 2 == 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n /= 2;
    }
    return ans;
}

int n, m;
int a[N][N];
int sx, sy;

long long dp[N * N];

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
    #endif // SOMETHING
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d%d", &sx, &sy);
    vector<pair<int, pair<int, int> > > v;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            v.push_back(m_p(a[i][j], m_p(i, j)));
        }
    }
    sort(v.begin(), v.end());
    long long q = 0, sdp = 0, sx = 0, sqx = 0, sy = 0, sqy = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (i && v[i].first != v[i - 1].first)
        {
            int j = i - 1;
            while (1)
            {
                long long x = v[j].second.first;
                long long y = v[j].second.second;
                ++q;
                sdp = (sdp + dp[j]) % M;
                sx = (sx + x) % M;
                sqx = (sqx + x * x) % M;
                sy = (sy + y) % M;
                sqy = (sqy + y * y) % M;
                if (!j || v[j - 1].first != v[j].first)
                    break;
                --j;
            }
        }
        long long x = v[i].second.first;
        long long y = v[i].second.second;
        dp[i] = (((q * x * x) % M + ((-2 * sx * x) % M + M) % M + sqx) % M * ast(q, M - 2)) % M;
        dp[i] = (((q * y * y) % M + ((-2 * sy * y) % M + M) % M + sqy) % M * ast(q, M - 2)) % M + dp[i];
        dp[i] = (dp[i] + sdp * ast(q, M - 2)) % M;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        if (m_p(::sx, ::sy) == v[i].second)
        {
            printf("%lld\n", dp[i]);
            return 0;
        }
    }
    return 0;
}