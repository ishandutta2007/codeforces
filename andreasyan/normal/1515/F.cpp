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
const int N = 300005;

int n, m, k;
ll a[N];
vector<int> g[N];
vector<int> gi[N];

int p[N];
int fi(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = fi(p[x]);
}

void kpc(int x, int y)
{
    x = fi(x);
    y = fi(y);
    p[x] = y;
}

ll s[N];
int q[N];
int u[N];
vector<int> v;
void dfs(int x, int p)
{
    s[x] = a[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        u[h] = gi[x][i];
        dfs(h, x);
        q[x] += (q[h] + 1);
        s[x] += s[h];
    }
    if (s[x] >= q[x] * 1LL * k)
    {
        v.push_back(x);
    }
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
        {
            swap(g[x][i], g[x].back());
            break;
        }
    }
    if (x != p)
        g[x].pop_back();
}

bool c[N];

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        p[i] = i;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (fi(x) == fi(y))
            continue;
        kpc(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
        gi[x].push_back(i);
        gi[y].push_back(i);
    }

    dfs(1, 1);

    if (s[1] < q[1] * 1LL * k)
    {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int ii = 0; ii < v.size(); ++ii)
    {
        set<pair<ll, int> > s;

        int x = v[ii];
        c[x] = true;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            s.insert(m_p(a[h], h));
        }

        while (!s.empty())
        {
            int x = (--s.end())->se;
            s.erase((--s.end()));

            cout << u[x] << "\n";
            if (c[x])
                continue;
            c[x] = true;
            for (int i = 0; i < g[x].size(); ++i)
            {
                int h = g[x][i];
                s.insert(m_p(a[h], h));
            }
        }

        a[x] = (::s[x] - q[x] * 1LL * k);
    }
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