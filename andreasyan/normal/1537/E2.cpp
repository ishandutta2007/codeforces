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
const pair<int, int> M = m_p(993019889, 997084241);
const int P = 307;

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

int n, k;
char a[N];

pair<int, int> p[N];

vector<pair<int, int> > pp[N];
vector<pair<int, int> > uu[N];

pair<int, int> f(int i, int k)
{
    if (i < k)
        return p[i];
    pair<int, int> h;
    h = pro(p[k - 1], pp[k][(i + 1) / k - 1]);
    if ((i + 1) % k - 1 >= 0)
        h = sum(h, pro(uu[k][(i + 1) / k], p[(i + 1) % k - 1]));
    return h;
}

void solv()
{
    cin >> n >> k;
    cin >> a;
    /*n = 500000;
    k = 500000;
    a[0] = 'z';
    for (int i = 1; i < n; ++i)
        a[i] = 'a';*/

    for (int i = 1; i < n; ++i)
    {
        if (a[0] < a[i])
        {
            n = i;
            break;
        }
    }

    p[0] = m_p(a[0], a[0]);
    for (int i = 1; i < n; ++i)
        p[i] = sum(p[i - 1], pro(ast[i], m_p(a[i], a[i])));

    for (int k = 1; k <= n; ++k)
    {
        pair<int, int> u = m_p(1, 1);
        uu[k].push_back(u);
        pp[k].push_back(u);
        for (int m = 1; m <= ::k / k + 3; ++m)
        {
            u = pro(u, ast[k]);
            uu[k].push_back(u);
            pp[k].push_back(sum(pp[k].back(), u));
        }
    }

    int ans = n;

    for (int i = 1; i < n; ++i)
    {
        if (a[0] == a[i])
        {
            int l = 0, r = k - 1;
            int u = k;
            while (l <= r)
            {
                int m = (l + r) / 2;
                pair<int, int> h1 = f(m, ans);
                pair<int, int> h2 = f(m, i);
                if (h1 != h2)
                {
                    u = m;
                    r = m - 1;
                }
                else
                    l = m + 1;
            }
            if (u < k)
            {
                if (a[(u % i)] < a[(u % ans)])
                    ans = i;
            }
        }
    }

    for (int i = 0; i < k; ++i)
        cout << a[(i % ans)];
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