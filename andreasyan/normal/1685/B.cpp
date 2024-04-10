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

int a, b, c, d;
int n;
char s[N];

bool g[N];

bool so(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.se - a.fi > b.se - b.fi;
}

void solv()
{
    cin >> a >> b >> c >> d;
    cin >> (s + 1);

    n = a + b + c * 2 + d * 2;

    int qa = 0;
    for (int i = 1; i <= n; ++i)
    {
        g[i] = false;
        if (s[i] == 'A')
            ++qa;
    }

    if (qa != a + c + d)
    {
        cout << "NO\n";
        return;
    }

    set<int> ss;
    for (int i = 1; i < n; ++i)
    {
        if (s[i] != s[i + 1])
        {
            ss.insert(i);
            ss.insert(i + 1);
        }
    }

    vector<int> v;
    for (auto it = ss.begin(); it != ss.end(); ++it)
        v.push_back(*it);

    vector<pair<int, int> > u;

    int l = -1;
    for (int i = 0; i < sz(v); ++i)
    {
        if (i == 0 || v[i] != v[i - 1] + 1 || s[v[i]] == s[v[i - 1]])
        {
            if (l != -1)
                u.push_back(m_p(l, v[i - 1]));
            l = v[i];
        }
    }
    if (!v.empty())
        u.push_back(m_p(l, v.back()));

    sort(all(u), so);

    int qc = 0;
    int qd = 0;
    for (int i = 0; i < sz(u); ++i)
    {
        if (s[u[i].fi] == 'A' && s[u[i].se] == 'B')
        {
            qc += (u[i].se - u[i].fi + 1) / 2;
        }
        if (s[u[i].fi] == 'B' && s[u[i].se] == 'A')
        {
            qd += (u[i].se - u[i].fi + 1) / 2;
        }
    }

    if (c <= qc && d <= qd)
    {
        cout << "YES\n";
        return;
    }
    if (d > qd)
    {
        swap(d, c);
        swap(qd, qc);
        reverse(s + 1, s + n + 1);
        for (int i = 0; i < sz(u); ++i)
        {
            swap(u[i].fi, u[i].se);
            u[i].fi = n - u[i].fi + 1;
            u[i].se = n - u[i].se + 1;
        }
    }
    if (c > qc)
    {
        for (int i = 0; i < sz(u); ++i)
        {
            if (s[u[i].fi] == 'A' && s[u[i].se] == 'B')
            {
                for (int j = u[i].fi; j <= u[i].se; j += 2)
                {
                    if (c)
                    {
                        --c;
                        g[j] = g[j + 1] = true;
                    }
                }
            }
        }
        for (int i = 0; i < sz(u); ++i)
        {
            if (s[u[i].fi] == s[u[i].se])
            {
                if (s[u[i].fi] == 'A')
                {
                    for (int j = u[i].fi; j < u[i].se; ++j)
                    {
                        if (!g[j] && !g[j + 1] && s[j] == 'A' && s[j + 1] == 'B' && c)
                        {
                            g[j] = g[j + 1] = true;
                            --c;
                        }
                    }
                }
                else
                {
                    for (int j = u[i].se - 1; j >= u[i].fi; --j)
                    {
                        if (!g[j] && !g[j + 1] && s[j] == 'A' && s[j + 1] == 'B' && c)
                        {
                            g[j] = g[j + 1] = true;
                            --c;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < sz(u); ++i)
        {
            if (s[u[i].fi] == 'B' && s[u[i].se] == 'A')
            {
                for (int j = u[i].fi; j < u[i].se; ++j)
                {
                    if (!g[j] && !g[j + 1] && s[j] == 'A' && s[j + 1] == 'B' && c)
                    {
                        g[j] = g[j + 1] = true;
                        --c;
                    }
                }
            }
        }
        for (int i = 1; i < n; ++i)
        {
            if (!g[i] && !g[i + 1] && s[i] == 'B' && s[i + 1] == 'A' && d)
            {
                --d;
                g[i] = g[i + 1] = true;
            }
        }
    }

    if (!c && !d)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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