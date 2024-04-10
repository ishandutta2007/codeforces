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
const int N = 1003;
const pair<int, int> M = m_p(993019889, 997084241);
const int P = 307;

bool prime(int x)
{
    for (int i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

pair<int, int> sum(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi + b.fi) % M.fi, (a.se + b.se) % M.se);
}

pair<int, int> dif(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi - b.fi + M.fi) % M.fi, (a.se - b.se + M.se) % M.se);
}

pair<int, int> pro(const pair<int, int>& a, const pair<int, int>& b)
{
    return m_p((a.fi * 1LL * b.fi) % M.fi, (a.se * 1LL * b.se) % M.se);
}

pair<int, int> ast[N];
void pre()
{
    ast[0] = m_p(1, 1);
    for (int i = 1; i < N; ++i)
        ast[i] = pro(ast[i - 1], m_p(P, P));
}

int n;
pair<int, int> a[N];

bool sos(const pair<int, int>& a, const pair<int, int>& b)
{
    return a.se < b.se;
}

char ans[N][N];

bool solv()
{
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);

    int anss = a[1].fi + 1;

    for (int i = 1; i <= anss; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            ans[i][j] = '0';
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= a[i].fi; ++j)
            ans[j][i] = '1';
    }

    set<pair<int, int> > ss;

    for (int i = anss - 1; i > 1; --i)
    {
        pair<int, int> h = m_p(0, 0);
        for (int j = 1; j <= n; ++j)
            h = sum(h, pro(ast[j], m_p(ans[i][j], ans[i][j])));
        if (ss.find(h) == ss.end())
        {
            ss.insert(h);
            continue;
        }

        bool f = false;
        for (int j = n; j >= 1; --j)
        {
            if (ans[i][j] != ans[anss][j])
            {
                h = dif(h, pro(ast[j], m_p(ans[i][j], ans[i][j])));
                h = sum(h, pro(ast[j], m_p(ans[anss][j], ans[anss][j])));
                swap(ans[i][j], ans[anss][j]);
                if (ss.find(h) == ss.end())
                {
                    ss.insert(h);
                    f = true;
                    break;
                }
                h = dif(h, pro(ast[j], m_p(ans[i][j], ans[i][j])));
                h = sum(h, pro(ast[j], m_p(ans[anss][j], ans[anss][j])));
                swap(ans[i][j], ans[anss][j]);
            }
        }
        if (f)
            continue;
        for (int j = 1; j <= n; ++j)
        {
            if (ans[i][j] != ans[1][j])
            {
                h = dif(h, pro(ast[j], m_p(ans[i][j], ans[i][j])));
                h = sum(h, pro(ast[j], m_p(ans[1][j], ans[1][j])));
                swap(ans[i][j], ans[1][j]);
                if (ss.find(h) == ss.end())
                {
                    ss.insert(h);
                    f = true;
                    break;
                }
                h = dif(h, pro(ast[j], m_p(ans[i][j], ans[i][j])));
                h = sum(h, pro(ast[j], m_p(ans[1][j], ans[1][j])));
                swap(ans[i][j], ans[1][j]);
            }
        }
    }
    pair<int, int> h1 = m_p(0, 0);
    pair<int, int> h2 = m_p(0, 0);
    for (int j = 1; j <= n; ++j)
    {
        h1 = sum(h1, pro(ast[j], m_p(ans[1][j], ans[1][j])));
        h2 = sum(h2, pro(ast[j], m_p(ans[anss][j], ans[anss][j])));
    }
    for (int j = n; j >= 1; --j)
    {
        if (ss.find(h1) == ss.end() && ss.find(h2) == ss.end() && h1 != h2)
            break;
        if (ans[anss][j] != ans[1][j])
        {
            h1 = dif(h1, pro(ast[j], m_p(ans[1][j], ans[1][j])));
            h2 = dif(h2, pro(ast[j], m_p(ans[anss][j], ans[anss][j])));
            swap(ans[anss][j], ans[1][j]);
            h1 = sum(h1, pro(ast[j], m_p(ans[1][j], ans[1][j])));
            h2 = sum(h2, pro(ast[j], m_p(ans[anss][j], ans[anss][j])));
            if (ss.find(h1) == ss.end() && ss.find(h2) == ss.end() && h1 != h2)
                break;
            h1 = dif(h1, pro(ast[j], m_p(ans[1][j], ans[1][j])));
            h2 = dif(h2, pro(ast[j], m_p(ans[anss][j], ans[anss][j])));
            swap(ans[anss][j], ans[1][j]);
            h1 = sum(h1, pro(ast[j], m_p(ans[1][j], ans[1][j])));
            h2 = sum(h2, pro(ast[j], m_p(ans[anss][j], ans[anss][j])));
        }
    }

    /*{
        set<string> ss;
        for (int i = 1; i <= anss; ++i)
        {
            string s;
            for (int j = 1; j <= n; ++j)
                s += ans[i][j];
            ss.insert(s);
        }
        if (sz(ss) != anss)
        {
            //sort(a + 1, a + n + 1, sos);
            cout << n << "\n";
            for (int i = 1; i <= n; ++i)
                cout << a[i].fi << ' ';
            cout << "\n";

            cout << anss << "\n";
            for (int i = anss; i >= 1; --i)
            {
                for (int j = 1; j <= n; ++j)
                {
                    cout << ans[i][j];
                }
                cout << "\n";
            }
            return false;
        }
        for (int j = 1; j <= n; ++j)
        {
            int q = 0;
            for (int i = 1; i <= anss; ++i)
            {
                q += ans[i][j] - '0';
            }
            if (q != a[j].fi)
            {
                cout << "Not good\n";
                exit(0);
            }
        }
        return true;
    }*/

    vector<int> u(n + 5);
    for (int i = 1; i <= n; ++i)
        u[a[i].se] = i;

    cout << anss << "\n";
    for (int i = anss; i >= 1; --i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cout << ans[i][u[j]];
        }
        cout << "\n";
    }
    return true;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    pre();

    /*int st = 1000;
    while (st--)
    {
        n = rnf() % 10 + 1;
        for (int i = 1; i <= n; ++i)
        {
            a[i].se = i;
            a[i].fi = rnf() % n + 1;
        }
        if (!solv())
        {
            solv();
            return 0;
        }
    }
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            a[i].se = i;
            cin >> a[i].fi;
        }
        solv();
    }
    return 0;
}