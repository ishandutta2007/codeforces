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

int n, c, q;
int p[N];
int x[N];

vector<pair<int, int> > ans[N];

vector<pair<ll, int> > v[5];
vector<int> vv[5];

ll ways(int n, int c)
{
    if (n == 0)
        return 1;
    ll ans = 0;
    ll yans = 1;
    ans += yans;
    for (int i = n - 1; i >= n - c; --i)
    {
        yans *= i;
        yans /= ((n - 1) - i + 1);
        ans += yans;
    }
    return ans;
}

ll pp[N];
void solv()
{
    cin >> n >> c >> q;

    for (int i = 1; i <= n; ++i)
        ans[i].clear();
    for (int i = 0; i <= c; ++i)
    {
        v[i].clear();
        vv[i].clear();
    }

    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= q; ++i)
    {
        ll y;
        cin >> x[i] >> y;
        if (y > ways(n, c))
            ans[i].push_back(m_p(-1, -1));
        else
            v[c].push_back(m_p(y, i));
    }

    for (int k = c; k >= 0; --k)
    {
        if (k != c)
        {
            for (int i = 1; i <= n; ++i)
            {
                pp[i] = pp[i - 1];
                for (int j = i + 1; j <= n && j - i <= k; ++j)
                {
                    if (p[j] < p[i])
                        pp[i] += ways(n - j, k - (j - i));
                }
            }
            for (int i = 0; i < v[k].size(); ++i)
                v[k][i].fi += pp[vv[k][i]];
        }

        deque<pair<int, int> > q;
        q.push_back(m_p(n, n));
        for (int i = n; i >= 1; --i)
        {
            vector<pair<int, int> > v;
            for (int j = i + 1; j <= n && j - i <= k; ++j)
            {
                v.push_back(m_p(p[j], j));
            }
            sort(all(v));
            for (int j = 0; j < sz(v); ++j)
            {
                if (v[j].fi > p[i])
                    q.push_back(m_p(i, v[j].se));
            }
            for (int j = sz(v) - 1; j >= 0; --j)
            {
                if (v[j].fi < p[i])
                    q.push_front(m_p(i, v[j].se));
            }
        }

        sort(all(v[k]));
        ll u = 0;
        int j = 0;
        for (int i = 0; i < v[k].size(); ++i)
        {
            while (v[k][i].fi > u + ways(n - q[j].se, k - (q[j].se - q[j].fi)))
            {
                u += ways(n - q[j].se, k - (q[j].se - q[j].fi));
                ++j;
            }
            ans[v[k][i].se].push_back(q[j]);
            if (q[j] != m_p(n, n))
            {
                v[k - (q[j].se - q[j].fi)].push_back(m_p(v[k][i].fi - u, v[k][i].se));
                vv[k - (q[j].se - q[j].fi)].push_back(q[j].se);
            }
        }
    }

    for (int i = 1; i <= q; ++i)
    {
        if (!ans[i].empty() && ans[i][0].fi == -1)
        {
            cout << "-1\n";
            continue;
        }
        bool z = false;
        for (int j = 0; j < ans[i].size(); ++j)
        {
            if (ans[i][j].fi <= x[i] && x[i] <= ans[i][j].se)
            {
                cout << p[ans[i][j].se - (x[i] - ans[i][j].fi)] << "\n";
                z = true;
                break;
            }
        }
        if (!z)
            cout << p[x[i]] << "\n";
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}