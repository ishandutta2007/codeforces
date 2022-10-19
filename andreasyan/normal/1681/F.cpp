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
const int N = 500005;

int n;
vector<pair<int, int> > g[N];

vector<int> v[N];
int q[N];
int tin[N], tout[N], ti;
void dfs(int x, int p)
{
    tin[x] = ++ti;
    q[x] = 1;
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i].fi;
        if (h == p)
            continue;
        dfs(h, x);
        v[g[x][i].se].push_back(h);
        q[x] += q[h];
    }
    tout[x] = ti;
}

int p[N];
int q0[N];

void solv()
{
    cin >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back(m_p(y, z));
        g[y].push_back(m_p(x, z));
    }

    dfs(1, 1);

    ll ans = 0;
    for (int x = 1; x <= n; ++x)
        p[x] = 1;
    for (int z = 1; z <= n; ++z)
    {
        set<pair<int, int> > s;
        for (int i = 0; i < v[z].size(); ++i)
        {
            int x = v[z][i];
            while (1)
            {
                if (s.empty())
                    break;
                auto it = s.lower_bound(m_p(tin[x], 0));
                if (it == s.end())
                    break;

                int h = it->se;
                if (tout[h] <= tout[x])
                {
                    s.erase(it);
                    p[h] = x;
                    q0[x] += q[h];
                }
                else
                    break;
            }
            s.insert(m_p(tin[x], x));
        }
        q0[1] = 0;
        while (!s.empty())
        {
            int h = s.begin()->se;
            s.erase(s.begin());
            q0[1] += q[h];
        }

        for (int i = 0; i < v[z].size(); ++i)
        {
            int x = v[z][i];
            ans += (q[x] - q0[x]) * 1LL * (q[p[x]] - q0[p[x]]);
        }
    }

    cout << ans << "\n";
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