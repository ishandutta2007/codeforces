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

int n;
vector<int> g[N];
int p[N];

int q[N];
void dfs0(int x)
{
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs0(h);
        q[x] += q[h];
    }
}

vector<int> v;
void dfsv(int x)
{
    v.push_back(x);
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfsv(h);
    }
}

multiset<int> s, s0, s1;

int ans[N];
void dfs(int x)
{
    if (x == 4)
        cout << "";

    int maxu = -1, maxh = -1;
    int minu = N;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        minu = min(minu, q[h]);
        if (q[h] > maxu)
        {
            maxu = q[h];
            maxh = h;
        }
    }
    if (q[x] != n)
    {
        minu = min(minu, n - q[x]);
        maxu = max(maxu, n - q[x]);
    }

    s0.erase(s0.find(q[x] * 2));

    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == maxh)
            continue;
        s1.insert(q[x] * 2);
        dfs(h);
        s1.erase(s1.find(q[x] * 2));

        v.clear();
        dfsv(h);

        s.clear();
        for (int i = 0; i < sz(v); ++i)
            s0.insert(q[v[i]] * 2);
    }

    if (maxh != -1)
    {
        s1.insert(q[x] * 2);
        dfs(maxh);
        s1.erase(s1.find(q[x] * 2));
    }

    ans[x] = maxu;
    if (maxh != -1 && q[maxh] == maxu)
    {
        auto it = s.lower_bound(maxu - minu);
        if (it != s.end())
            ans[x] = min(ans[x], max(minu + *it / 2, maxu - *it / 2));
        if (it != s.begin())
        {
            --it;
            ans[x] = min(ans[x], max(minu + *it / 2, maxu - *it / 2));
        }

        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == maxh)
                continue;
            ans[x] = max(ans[x], q[h]);

            v.clear();
            dfsv(h);

            for (int i = 0; i < sz(v); ++i)
            {
                s.insert(q[v[i]] * 2);
                s0.erase(s0.find(q[v[i]] * 2));
            }
        }
        s.insert(q[x] * 2);
        ans[x] = max(ans[x], n - q[x]);
    }
    else
    {
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (h == maxh)
                continue;

            v.clear();
            dfsv(h);

            for (int i = 0; i < sz(v); ++i)
            {
                s.insert(q[v[i]] * 2);
                s0.erase(s0.find(q[v[i]] * 2));
            }
        }
        s.insert(q[x] * 2);

        auto it = s0.lower_bound(maxu - minu);
        if (it != s0.end())
            ans[x] = min(ans[x], max(minu + *it / 2, maxu - *it / 2));
        if (it != s0.begin())
        {
            --it;
            ans[x] = min(ans[x], max(minu + *it / 2, maxu - *it / 2));
        }

        if (!s1.empty())
        {
            auto it = s1.lower_bound(maxu - minu + 2 * q[x]);
            if (it != s1.end())
                ans[x] = min(ans[x], max(minu + *it / 2 - q[x], maxu - *it / 2 + q[x]));
            if (it != s1.begin())
            {
                --it;
                ans[x] = min(ans[x], max(minu + *it / 2 - q[x], maxu - *it / 2 + q[x]));
            }
        }

        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            ans[x] = max(ans[x], q[h]);
        }
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;
        p[y] = x;
        g[x].push_back(y);
    }

    if (n == 1)
    {
        cout << "0\n";
        return;
    }

    dfs0(g[0][0]);

    for (int i = 1; i <= n; ++i)
        s0.insert(q[i] * 2);

    dfs(g[0][0]);

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}