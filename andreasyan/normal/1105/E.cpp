#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int N = 100005, M = 20;

int n, m;
int u[N];

int z;
map<string, int> mp;
vector<int> v[N];

long long xx[M + M];

bool c[(1 << M)];
int dp[(1 << M)];

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int ty;
        cin >> ty;
        if (ty == 1)
        {
            u[i] = i;
            continue;
        }
        u[i] = u[i - 1];
        string s;
        cin >> s;
        if (mp.find(s) == mp.end())
            mp[s] = z++;
        v[u[i]].push_back(mp[s]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (v[i].size() <= 1)
            continue;
        long long yx = 0;
        for (int j = 0; j < v[i].size(); ++j)
            yx |= (1LL << v[i][j]);
        for (int i = 0; i < m; ++i)
        {
            if ((yx & (1LL << i)))
                xx[i] |= (yx ^ (1LL << i));
        }
    }
    c[0] = true;
    for (int x = 0; x < (1 << (m / 2)); ++x)
    {
        if (c[x])
        {
            int q = 0;
            for (int i = 0; i < (m / 2); ++i)
            {
                if ((x & (1 << i)))
                {
                    ++q;
                    continue;
                }
                if (!(xx[i] & x))
                {
                    c[(x | (1 << i))] = true;
                }
            }
            dp[x] = q;
            continue;
        }
        for (int i = 0; i < (m / 2); ++i)
        {
            if ((x & (1 << i)))
                dp[x] = max(dp[x], dp[(x ^ (1 << i))]);
        }
    }
    int ans = 0;
    memset(c, false, sizeof c);
    c[0] = true;
    for (int x = 0; x < (1 << (m / 2 + m % 2)); ++x)
    {
        if (c[x])
        {
            int q = 0;
            long long yx = 0;
            for (int i = 0; i < (m / 2 + m % 2); ++i)
            {
                if ((x & (1 << i)))
                {
                    ++q;
                    yx |= (xx[i + (m / 2)]);
                    continue;
                }
                if (!((xx[i + (m / 2)] >> (m / 2)) & x))
                {
                    c[(x | (1 << i))] = true;
                }
            }
            int y = 0;
            for (int i = 0; i < (m / 2); ++i)
            {
                if (!(yx & (1 << i)))
                    y |= (1 << i);
            }
            ans = max(ans, q + dp[y]);
        }
    }
    cout << ans << endl;
    return 0;
}