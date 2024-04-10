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
const int N = 2003;
const int INF = 1000000009;

bool so(const pair<string, int>& a, const pair<string, int>& b)
{
    return sz(a.fi) < sz(b.fi);
}

int tz;
int t[N * 12][12];
int ts[N * 12];

vector<pair<int, int> > g[N];
vector<string> gs[N];
vector<int> gx[N];

int dp[(1 << 12)][N];
pair<int, int> p[(1 << 12)][N];

int u[(1 << 12)];
string us[(1 << 12)];

void solv()
{
    int n;
    vector<pair<string, int> > a;

    cin >> n;
    while (n--)
    {
        int c = 1;
        string s = "";
        for (int i = 0; i < 2; ++i)
        {
            if (s.empty())
                s += (rnf() % 12 + 'a');
            else
                s += ((s.back() - 'a' + 1 + (rnf() % 11)) % 12 + 'a');
        }
        for (int i = 0; i < sz(s) - 1; ++i)
            assert(s[i] != s[i + 1]);
        cin >> c >> s;
        int m = s.size();

        bool g[300] = {};
        deque<char> u;
        u.push_back(s[0]);
        g[s[0]] = true;
        int j = 0;
        for (int i = 1; i < m; ++i)
        {
            if (!g[s[i]])
            {
                if (j == sz(u) - 1)
                {
                    u.push_back(s[i]);
                    ++j;
                }
                else if (j == 0)
                {
                    u.push_front(s[i]);
                }
                else
                {
                    g[0] = true;
                    break;
                }
                g[s[i]] = true;
            }
            else
            {
                if (j + 1 < sz(u) && u[j + 1] == s[i])
                    ++j;
                else if (j - 1 >= 0 && u[j - 1] == s[i])
                    --j;
                else
                {
                    g[0] = true;
                    break;
                }
            }
        }

        if (!g[0])
        {
            s = "";
            for (int i = 0; i < sz(u); ++i)
                s += u[i];
            a.push_back(m_p(s, c));
            reverse(all(s));
            a.push_back(m_p(s, c));
        }
    }

    sort(all(a), so);
    reverse(all(a));
    vector<pair<string, int> > b;
    while (!a.empty())
    {
        pair<string, int> s = a.back();
        a.pop_back();
        bool z = false;
        for (int i = 0; i < sz(a); ++i)
        {
            if (a[i].fi == s.fi)
            {
                a[i].se += s.se;
                z = true;
                break;
            }
        }
        if (!z)
        {
            b.push_back(s);
            int pos = 0;
            for (int i = 0; i < sz(s.fi); ++i)
            {
                if (!t[pos][s.fi[i] - 'a'])
                    t[pos][s.fi[i] - 'a'] = ++tz;
                pos = t[pos][s.fi[i] - 'a'];
            }
            ts[pos] += s.se;
        }
    }

    a = b;
    n = sz(a);

    for (int i = 0; i < n; ++i)
    {
        int ss = 0;
        for (int j = 0; j < sz(a[i].fi); ++j)
        {
            int pos = 0;
            for (int k = j; k < sz(a[i].fi); ++k)
            {
                if (!t[pos][a[i].fi[k] - 'a'])
                    break;
                pos = t[pos][a[i].fi[k] - 'a'];
                ss += ts[pos];
            }
        }
        g[n].push_back(m_p(i, ss));
        gs[n].push_back(a[i].fi);
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            for (int l = 1; l < sz(a[i].fi); ++l)
            {
                bool z = true;
                for (int k = l; k < sz(a[i].fi); ++k)
                {
                    if (k - l >= sz(a[j].fi) || a[i].fi[k] != a[j].fi[k - l])
                    {
                        z = false;
                        break;
                    }
                }
                if (z)
                {
                    string s = "";
                    for (int k = sz(a[i].fi) - l; k < sz(a[j].fi); ++k)
                        s += a[j].fi[k];
                    int ss = 0;
                    string y = a[i].fi + s;
                    for (int j = 0; j < sz(y); ++j)
                    {
                        int pos = 0;
                        for (int k = j; k < sz(y); ++k)
                        {
                            if (!t[pos][y[k] - 'a'])
                                break;
                            pos = t[pos][y[k] - 'a'];
                            if (k >= sz(a[i].fi))
                                ss += ts[pos];
                        }
                    }
                    g[i].push_back(m_p(j, ss));
                    gs[i].push_back(s);
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i <= n; ++i)
    {
        sum += sz(g[i]);
        for (int j = 0; j < sz(gs[i]); ++j)
        {
            int x = 0;
            for (int k = 0; k < sz(gs[i][j]); ++k)
                x |= (1 << (gs[i][j][k] - 'a'));
            gx[i].push_back(x);
        }
    }
    assert(sum <= 100000);

    for (int x = 0; x < (1 << 12); ++x)
    {
        for (int i = 0; i <= n; ++i)
        {
            dp[x][i] = -INF;
        }
    }
    dp[0][n] = 0;
    for (int x = 0; x < (1 << 12); ++x)
    {
        for (int i = 0; i <= n; ++i)
        {
            if (dp[x][i] < 0)
                continue;
            for (int j = 0; j < sz(g[i]); ++j)
            {
                if ((x & gx[i][j]) == 0)
                {
                    if (dp[x][i] + g[i][j].se > dp[(x | gx[i][j])][g[i][j].fi])
                    {
                        dp[(x | gx[i][j])][g[i][j].fi] = dp[x][i] + g[i][j].se;
                        p[(x | gx[i][j])][g[i][j].fi] = m_p(i, j);
                    }
                }
            }
        }
    }

    for (int x = 0; x < (1 << 12); ++x)
    {
        int maxu = -INF;
        for (int i = 0; i <= n; ++i)
        {
            maxu = max(maxu, dp[x][i]);
        }
        u[x] = max(maxu, 0);
        int x0 = x;
        if (maxu > 0)
        {
            for (int i = 0; i <= n; ++i)
            {
                if (dp[x][i] == maxu)
                {
                    vector<string> v;
                    while (x)
                    {
                        int ii = p[x][i].fi;
                        int jj = p[x][i].se;
                        int xx = (x ^ gx[ii][jj]);
                        v.push_back(gs[ii][jj]);
                        x = xx;
                        i = ii;
                        //assert(sz(v) <= 20);
                    }
                    reverse(all(v));
                    string s = "";
                    for (int i = 0; i < sz(v); ++i)
                        s += v[i];
                    us[x0] = s;
                    break;
                }
            }
        }
        x = x0;
    }

    for (int x = 0; x < (1 << 12); ++x)
    {
        for (int y = x; y; y = ((y - 1) & x))
        {
            if (y == x)
                continue;
            int z = (x ^ y);
            if (u[y] + u[z] > u[x])
            {
                u[x] = u[y] + u[z];
                us[x] = us[y] + us[z];
            }
        }
    }

    string ans = us[(1 << 12) - 1];
    bool g[300] = {};
    for (int i = 0; i < sz(ans); ++i)
        g[ans[i]] = true;
    for (char x = 'a'; x <= 'l'; ++x)
    {
        if (!g[x])
            ans += x;
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