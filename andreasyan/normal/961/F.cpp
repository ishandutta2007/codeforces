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
const int N = 1000006;
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
char a[N];

pair<int, int> p[N];

int ans[N];

void solv()
{
    cin >> n;
    cin >> (a + 1);

    for (int i = 1; i <= n; ++i)
        p[i] = sum(p[i - 1], pro(ast[i], m_p(a[i], a[i])));

    vector<pair<int, int> > v;
    for (int i = 1; i <= n / 2; ++i)
    {
        int j = n - i + 1;
        if (a[i] != a[j])
            continue;

        int l = 1, r = i - 1;
        int u = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (pro(dif(p[i + m], p[i - m - 1]), ast[n - (i + m)]) == pro(dif(p[j + m], p[j - m - 1]), ast[n - (j + m)]))
            {
                u = m;
                l = m + 1;
            }
            else
                r = m - 1;
        }
        v.push_back(m_p(i, i - u));
    }

    for (int i = 1; i <= n / 2 + n % 2; ++i)
        ans[i] = -1;

    int j = n / 2 + n % 2;
    for (int i = sz(v) - 1; i >= 0; --i)
    {
        j = min(j, v[i].fi);
        while (j >= v[i].se)
        {
            ans[j] = (v[i].fi - j) * 2 + 1;
            --j;
        }
    }

    for (int i = 1; i <= n / 2 + n % 2; ++i)
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

    pre();

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}