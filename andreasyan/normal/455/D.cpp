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
const int N = 100005, S = 320;

int n;
int a[N];

vector<pair<int, int> > v;
vector<int> u;

int z;
short q[S * 3 + 10][N];

int ya[N];
void bil()
{
    for (int i = 0; i < sz(v); ++i)
    {
        for (int k = v[i].fi; k <= v[i].se; ++k)
            --q[u[i]][a[k]];
    }

    int j = 0;
    for (int i = 0; i < sz(v); ++i)
    {
        for (int k = v[i].fi; k <= v[i].se; ++k)
            ya[++j] = a[k];
    }
    for (int i = 1; i <= n; ++i)
        a[i] = ya[i];

    v.clear();
    u.clear();
    z = 0;

    for (int i = 1; i <= n; i += S)
    {
        v.push_back(m_p(i, min(n, i + S - 1)));
        u.push_back(++z);
        for (int k = v.back().fi; k <= v.back().se; ++k)
            ++q[z][a[k]];
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    v.push_back(m_p(1, n));
    u.push_back(++z);
    for (int i = 1; i <= n; ++i)
        ++q[z][a[i]];
    bil();

    int qq;
    cin >> qq;
    int ans = 0;
    while (qq--)
    {
        int ty;
        cin >> ty;

        if (ty == 1)
        {
            int l, r;
            cin >> l >> r;
            l = (l + ans - 1) % n + 1;
            r = (r + ans - 1) % n + 1;
            if (l > r)
                swap(l, r);

            int j = 1;
            int x = -1;
            for (int i = 0; i < sz(v); ++i)
            {
                if (j <= r && r <= j + v[i].se - v[i].fi)
                {
                    x = v[i].fi + r - j;
                    break;
                }
                j += (v[i].se - v[i].fi + 1);
            }
            assert(x != -1);

            j = 1;
            vector<pair<int, int> > nv;
            vector<int> nu;
            for (int i = 0; i < sz(v); ++i)
            {
                if (j <= l && r <= j + v[i].se - v[i].fi)
                {
                    nv.push_back(m_p(v[i].fi, v[i].fi + l - j - 1));
                    nu.push_back(u[i]);

                    for (int k = v[i].fi + l - j; k <= v[i].se; ++k)
                    {
                        q[u[i]][a[k]]--;
                    }

                    nv.push_back(m_p(x, x));
                    nu.push_back(0);

                    nv.push_back(m_p(v[i].fi + l - j, v[i].fi + r - j - 1));
                    nu.push_back(0);

                    nv.push_back(m_p(v[i].fi + r - j + 1, v[i].se));
                    nu.push_back(0);
                }
                else if (j <= l && l <= j + v[i].se - v[i].fi)
                {
                    nv.push_back(m_p(v[i].fi, v[i].fi + l - j - 1));
                    nu.push_back(u[i]);
                    for (int k = v[i].fi + l - j; k <= v[i].se; ++k)
                    {
                        q[u[i]][a[k]]--;
                    }

                    nv.push_back(m_p(x, x));
                    nu.push_back(0);

                    nv.push_back(m_p(v[i].fi + l - j, v[i].se));
                    nu.push_back(0);
                }
                else if (j <= r && r <= j + v[i].se - v[i].fi)
                {
                    nv.push_back(m_p(v[i].fi, v[i].fi + r - j - 1));
                    nu.push_back(u[i]);

                    for (int k = v[i].fi + r - j; k <= v[i].se; ++k)
                    {
                        q[u[i]][a[k]]--;
                    }
                    nv.push_back(m_p(v[i].fi + r - j + 1, v[i].se));
                    nu.push_back(0);
                }
                else
                {
                    nv.push_back(v[i]);
                    nu.push_back(u[i]);
                }

                j += (v[i].se - v[i].fi + 1);
            }
            assert(sz(nv) == sz(nu));

            v.clear();
            u.clear();
            for (int i = 0; i < sz(nv); ++i)
            {
                if (nv[i].fi > nv[i].se)
                    continue;
                v.push_back(nv[i]);
                u.push_back(nu[i]);
            }

            for (int i = 0; i < sz(v); ++i)
            {
                if (v[i].fi == v[i].se)
                    continue;
                if (u[i] == 0)
                {
                    u[i] = ++z;
                    for (int k = v[i].fi; k <= v[i].se; ++k)
                        q[z][a[k]]++;
                }
            }
        }
        else
        {
            int l, r, t;
            cin >> l >> r >> t;
            l = (l + ans - 1) % n + 1;
            r = (r + ans - 1) % n + 1;
            t = (t + ans - 1) % n + 1;
            if (l > r)
                swap(l, r);

            ans = 0;

            int j = 1;
            for (int i = 0; i < sz(v); ++i)
            {
                if (j <= l && r <= j + v[i].se - v[i].fi)
                {
                    for (int k = v[i].fi + l - j; k <= v[i].fi + r - j; ++k)
                    {
                        if (a[k] == t)
                            ++ans;
                    }
                    break;
                }
                if (l <= j && j + v[i].se - v[i].fi <= r)
                {
                    if (v[i].fi == v[i].se)
                    {
                        if (a[v[i].fi] == t)
                            ++ans;
                    }
                    else
                        ans += q[u[i]][t];
                }
                else if (j <= l && l <= j + v[i].se - v[i].fi)
                {
                    for (int k = v[i].fi + l - j; k <= v[i].se; ++k)
                    {
                        if (a[k] == t)
                            ++ans;
                    }
                }
                else if (j <= r && r <= j + v[i].se - v[i].fi)
                {
                    for (int k = v[i].fi; k <= v[i].fi + r - j; ++k)
                    {
                        if (a[k] == t)
                            ++ans;
                    }
                }
                j += (v[i].se - v[i].fi + 1);
            }

            cout << ans << "\n";
        }

        if (z >= S * 3 || sz(v) >= S * 3)
        {
            bil();
        }
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