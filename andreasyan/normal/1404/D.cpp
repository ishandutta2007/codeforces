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
const int N = 55;

int n;
bool c[N];
vector<pair<int, int> > v;
bool rec(int i)
{
    if (i == 2 * n)
    {
        assert(sz(v) == n);
        bool z = true;
        for (int x = 0; x < (1 << n); ++x)
        {
            int s = 0;
            for (int i = 0; i < n; ++i)
            {
                if (!(x & (1 << i)))
                    s = (s + v[i].fi) % (2 * n);
                else
                    s = (s + v[i].se) % (2 * n);
            }
            if (s == 0)
            {
                z = false;
                break;
            }
        }
        if (z)
        {
            cout << "First" << endl;
            for (int i = 0; i < n; ++i)
                cout << v[i].fi << ' ' << v[i].se << endl;
            return true;
        }
        return false;
    }
    if (c[i])
    {
        if (rec(i + 1))
            return true;
    }
    else
    {
        for (int j = i + 1; j < 2 * n; ++j)
        {
            if (!c[j])
            {
                c[i] = c[j] = true;
                v.push_back(m_p(i, j));
                if (rec(i + 1))
                    return true;
                v.pop_back();
                c[i] = c[j] = false;
            }
        }
    }
    return false;
}

void por()
{
    for (n = 2; n <= 14; n += 2)
    {
        cout << n << ' ';

        memset(c, false, sizeof c);
        v.clear();
        if (!rec(0))
            cout << "Second" << endl;
    }
}

void solv()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
    {
        cout << "First" << endl;

        vector<pair<int, int> > v;
        for (int i = 0; i < n - 2; i += 2)
            v.push_back(m_p(i, i + 1));
        v.push_back(m_p(n - 2, 2 * n - 2));
        v.push_back(m_p(n - 1, 2 * n - 1));
        for (int i = n; i < 2 * n - 2; i += 2)
            v.push_back(m_p(i, i + 1));

        vector<int> ans(n * 2 + 5);
        for (int i = 0; i < n; ++i)
        {
            if (v[i].fi == 0)
                v[i].fi = n * 2;
            if (v[i].se == 0)
                v[i].se = n * 2;
            ans[v[i].fi] = ans[v[i].se] = i + 1;
        }
        for (int i = 1; i <= n * 2; ++i)
            cout << ans[i] << ' ';
        cout << endl;
    }
    else
    {
        cout << "Second" << endl;

        vector<int> a(n * 2 + 5);
        for (int i = 1; i <= n * 2; ++i)
            cin >> a[i];

        vector<pair<int, int> > b;
        b.assign(n + 5, m_p(-1, -1));
        for (int i = 1; i <= n * 2; ++i)
        {
            if (b[a[i]].fi == -1)
                b[a[i]].fi = i;
            else
                b[a[i]].se = i;
        }

        vector<int> u(n * 2 + 5);
        for (int i = 1; i <= n; ++i)
        {
            u[b[i].fi] = b[i].se;
            u[b[i].se] = b[i].fi;
        }

        vector<vector<pair<int, int> > > g(n);
        for (int i = 1; i <= n; ++i)
        {
            g[b[i].fi % n].push_back(m_p(b[i].se % n, i));
            g[b[i].se % n].push_back(m_p(b[i].fi % n, i));
        }

        vector<int> ans;
        vector<bool> c, ci;
        c.assign(n, false);
        ci.assign(n + 5, false);
        for (int i = 0; i < n; ++i)
        {
            if (c[i])
                continue;
            int x = i;
            while (1)
            {
                c[x] = true;
                bool z = false;
                for (int i = 0; i < sz(g[x]); ++i)
                {
                    int h = g[x][i].fi;
                    int hi = g[x][i].se;
                    if (!c[h] && !ci[hi])
                    {
                        ci[hi] = true;
                        if (b[hi].fi % n == x)
                            ans.push_back(b[hi].fi);
                        else
                        {
                            assert(b[hi].se % n == x);
                            ans.push_back(b[hi].se);
                        }
                        z = true;
                        x = h;
                        break;
                    }
                }
                if (!z)
                {
                    int coi = i;
                    for (int i = 0; i < sz(g[x]); ++i)
                    {
                        int h = g[x][i].fi;
                        int hi = g[x][i].se;
                        if (h == coi && !ci[hi])
                        {
                            ci[hi] = true;
                            if (b[hi].fi % n == x)
                                ans.push_back(b[hi].fi);
                            else
                            {
                                assert(b[hi].se % n == x);
                                ans.push_back(b[hi].se);
                            }
                            z = true;
                            x = h;
                            break;
                        }
                    }
                    assert(z);
                    break;
                }
            }
        }

        assert(sz(ans) == n);

        int s = 0;
        for (int i = 0; i < n; ++i)
            s = (s + ans[i]) % (2 * n);
        if (s == n)
        {
            for (int i = 0; i < n; ++i)
                ans[i] = u[ans[i]];
        }

        s = 0;
        for (int i = 0; i < n; ++i)
            s = (s + ans[i]) % (2 * n);
        assert(s == 0);

        for (int i = 0; i < n; ++i)
            cout << ans[i] << ' ';
        cout << endl;
    }

    int zro;
    cin >> zro;
}

int main()
{
    #ifdef SOMETHING
    //freopen("input.txt", "r", stdin);
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