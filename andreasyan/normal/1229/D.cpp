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
const int N = 200005, M = 6;
 
int n, m;
vector<int> a[N];
 
vector<vector<int> > vv;
int u[120][120];
 
bool c[120];
int q;
void dfs(int x, vector<int>& v)
{
    if (c[x])
        return;
    c[x] = true;
    ++q;
    for (int i = 0; i < sz(v); ++i)
        dfs(u[x][v[i]], v);
}
 
int g[120];
 
void solv()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        a[i].assign(m, 0);
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
            --a[i][j];
        }
    }
 
    {
        vector<int> v;
        for (int i = 0; i < m; ++i)
            v.push_back(i);
        do
        {
            vv.push_back(v);
        } while (next_permutation(all(v)));
        sort(all(vv));
    }
 
    for (int i = 0; i < sz(vv); ++i)
    {
        for (int j = 0; j < sz(vv); ++j)
        {
            vector<int> nv;
            nv.assign(m, 0);
            for (int k = 0; k < m; ++k)
                nv[k] = vv[i][vv[j][k]];
            u[i][j] = lower_bound(all(vv), nv) - vv.begin();
        }
    }
 
    ll ans = 0;
    for (int ii = 1; ii <= n; ++ii)
    {
        g[lower_bound(all(vv), a[ii]) - vv.begin()] = ii;
 
        vector<pair<int, int> > t;
        for (int i = 0; i < sz(vv); ++i)
            t.push_back(m_p(g[i], i));
        sort(all(t));
        reverse(all(t));
 
        vector<int> v;
        memset(c, false, sizeof c);
        q = 0;
 
        int qd = 0;
        t.push_back(m_p(0, -1));
        for (int i = 0; i < sz(t) - 1; ++i)
        {
            if (!c[t[i].se])
            {
                v.push_back(t[i].se);
                ++qd;
                memset(c, false, sizeof c);
                q = 0;
                dfs(0, v);
            }
 
            ans += (t[i].fi - t[i + 1].fi) * q;
        }
 
        assert(qd <= 9);
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