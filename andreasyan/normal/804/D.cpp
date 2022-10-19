#include <bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
typedef long long ll;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;

int n, m, qq;
vector<int> g[N];

int c[N];
int k;

int d[N];
void dfs0(int x, int p)
{
    c[x] = k;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs0(h, x);
        d[x] = max(d[x], d[h] + 1);
    }
}

void dfs1(int x, int p, int dp)
{
    d[x] = max(d[x], dp + 1);
    int max1 = dp + 1, max2 = dp + 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (d[h] + 1 >= max1)
        {
            max2 = max1;
            max1 = d[h] + 1;
        }
        else if (d[h] + 1 >= max2)
            max2 = d[h] + 1;
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        if (d[h] + 1 == max1)
            dfs1(h, x, max2);
        else
            dfs1(h, x, max1);
    }
}

vector<int> v[N];
vector<ll> s[N];

map<pair<int, int>, double> mp;

void solv()
{
    scanf("%d%d%d", &n, &m, &qq);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int x = 1; x <= n; ++x)
    {
        if (!c[x])
        {
            ++k;
            dfs0(x, x);
            dfs1(x, x, -1);
        }
    }
    for (int x = 1; x <= n; ++x)
    {
        v[c[x]].push_back(d[x]);
    }
    for (int i = 1; i <= k; ++i)
    {
        sort(all(v[i]));
        s[i].assign(sz(v[i]) + 1, 0);
        for (int j = sz(v[i]) - 1; j >= 0; --j)
            s[i][j] = s[i][j + 1] + v[i][j];
    }

    while (qq--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x = c[x];
        y = c[y];
        if (x == y)
        {
            printf("-1\n");
            continue;
        }
        if (sz(v[x]) > sz(v[y]) || (sz(v[x]) == sz(v[y]) && x > y))
            swap(x, y);
        if (mp.find(m_p(x, y)) != mp.end())
        {
            printf("%.9f\n", mp[m_p(x, y)]);
            continue;
        }
        double ans = 0;
        int dd = max(v[x].back(), v[y].back());
        for (int i = 0; i < sz(v[x]); ++i)
        {
            int l = 0, r = sz(v[y]) - 1;
            int u = sz(v[y]);
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (v[y][m] + 1 + v[x][i] > dd)
                {
                    u = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            ans += (u * 1LL * dd);
            ans += s[y][u];
            ans += (sz(v[y]) - u) * 1LL * (v[x][i] + 1);
        }
        ans /= (sz(v[x]) * 1LL * sz(v[y]));
        printf("%.9f\n", ans);
        mp[m_p(x, y)] = ans;
    }
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    //ios_base::sync_with_stdio(false), cin.tie(0);
    solv();
    return 0;
}

//while ((double)clock() / CLOCKS_PER_SEC <= 0.9){}