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
const int N = 300005, m = 30;

int n, k;
int a[N];

int kb;

int z;
int t[N * m][2];
int h[N * m];

vector<int> rec(vector<pair<pair<int, int>, int> > v)
{
    if (v.empty())
        return {};

    vector<int> vb;
    for (int i = 0; i < sz(v); ++i)
    {
        vb.push_back(-1);
        for (int j = v[i].fi.se; j >= 0; --j)
        {
            if ((v[i].fi.fi & (1 << j)))
            {
                vb.back() = j;
                break;
            }
        }
    }

    vector<pair<pair<int, int>, int> > vv[m];
    vector<pair<int, int> > u[2];
    for (int i = 0; i < sz(v); ++i)
    {
        if (vb[i] > kb)
        {
            vv[vb[i]].push_back(m_p(m_p((v[i].fi.fi ^ (1 << vb[i])), vb[i] - 1), v[i].se));
        }
        else if (vb[i] == kb)
        {
            u[1].push_back(m_p((v[i].fi.fi ^ k), v[i].se));
        }
        else
        {
            u[0].push_back(m_p(v[i].fi.fi, v[i].se));
        }
    }

    vector<int> ans;
    for (int i = 0; i < m; ++i)
    {
        vector<int> yans = rec(vv[i]);
        for (int j = 0; j < sz(yans); ++j)
            ans.push_back(yans[j]);
    }

    z = 0;
    t[z][0] = t[z][1] = 0;
    h[z] = 0;
    for (int i = 0; i < sz(u[1]); ++i)
    {
        int pos = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            int g = 0;
            if ((u[1][i].fi & (1 << j)))
                g = 1;
            if (!t[pos][g])
            {
                t[pos][g] = ++z;
                t[z][0] = t[z][1] = 0;
                h[z] = 0;
            }
            pos = t[pos][g];
            h[pos] = u[1][i].se;
        }
    }

    bool zz = false;
    for (int i = 0; i < sz(u[0]); ++i)
    {
        int pos = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            int g = 0;
            if ((u[0][i].fi & (1 << j)))
                g = 1;

            if (!(k & (1 << j)))
            {
                if (t[pos][(g ^ 1)])
                {
                    ans.push_back(h[t[pos][(g ^ 1)]]);
                    ans.push_back(u[0][i].se);
                    zz = true;
                    break;
                }
            }
            if (!t[pos][g])
                break;
            pos = t[pos][g];

            if (j == 0)
            {
                ans.push_back(h[pos]);
                ans.push_back(u[0][i].se);
                zz = true;
                break;
            }
        }
        if (zz)
            break;
    }

    if (!zz)
    {
        if (!u[0].empty())
            ans.push_back(u[0][0].se);
        else if (!u[1].empty())
            ans.push_back(u[1][0].se);
    }

    return ans;
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    if (k == 0)
    {
        cout << n << "\n";
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << "\n";
        return;
    }

    vector<pair<pair<int, int>, int> > v;
    for (int i = 1; i <= n; ++i)
        v.push_back(m_p(m_p(a[i], m - 1), i));

    kb = -1;
    for (int j = m - 1; j >= 0; --j)
    {
        if ((k & (1 << j)))
        {
            kb = j;
            break;
        }
    }
    vector<int> ans = rec(v);

    if (sz(ans) < 2)
    {
        cout << "-1\n";
        return;
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        cout << ans[i] << ' ';
    cout << "\n";
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