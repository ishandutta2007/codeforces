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
const int N = 200005;

int n, k;
vector<int> g[N];

int d[N];
void dfs(int x, int p)
{
    d[x] = 0;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        if (h == p)
            continue;
        dfs(h, x);
        d[x] = max(d[x], d[h] + 1);
    }
}

int dia()
{
    dfs(1, 1);

    int x = 1;
    while (1)
    {
        if (d[x] == 0)
            break;
        for (int i = 0; i < g[x].size(); ++i)
        {
            int h = g[x][i];
            if (d[h] > d[x])
                continue;
            if (d[h] + 1 == d[x])
            {
                x = h;
                break;
            }
        }
    }

    dfs(x, x);

    return d[x];
}

void solv()
{
    cin >> n >> k;

    vector<pair<int, int> > ans;

    vector<int> v;
    for (int i = 1; i <= k; ++i)
        v.push_back(i);
    int u = k + 1;
    while (1)
    {
        if ((n - u + 1) > k)
        {
            for (int i = 0; i < sz(v); ++i)
            {
                ans.push_back(m_p(v[i], u));
                v[i] = u++;
            }
        }
        else
        {
            for (int i = 0; i < (n - u); ++i)
            {
                ans.push_back(m_p(v[i], u + i));
                v[i] = u + i;
            }
            for (int i = 0; i < sz(v); ++i)
            {
                ans.push_back(m_p(v[i], n));
            }
            break;
        }
    }

    for (int i = 0; i < sz(ans); ++i)
    {
        g[ans[i].fi].push_back(ans[i].se);
        g[ans[i].se].push_back(ans[i].fi);
    }
    cout << dia() << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i].fi << ' ' << ans[i].se << "\n";
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