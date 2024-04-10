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
const int N = 100005, INF = 1000000009;

int n, s1, s2;
int a[N];

pair<int, int> t[N * 4];
void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = m_p(a[tl], a[tl]);
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos].fi = min(t[pos * 2].fi, t[pos * 2 + 1].fi);
    t[pos].se = max(t[pos * 2].se, t[pos * 2 + 1].se);
}

pair<int, int> qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return m_p(INF, -INF);
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    pair<int, int> u1 = qry(tl, m, l, min(m, r), pos * 2);
    pair<int, int> u2 = qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1);
    return m_p(min(u1.fi, u2.fi), max(u1.se, u2.se));
}

bool stg(int d)
{
    int u1 = 1;
    while (u1 <= n && abs(s1 - a[u1]) <= d)
    {
        ++u1;
    }
    int u2 = 1;
    while (u2 <= n && abs(s2 - a[u2]) <= d)
    {
        ++u2;
    }

    int u = max(u1, u2);

    int j = 1;
    while (1)
    {
        if (u == n + 1)
            break;
        if (j >= u)
            break;
        pair<int, int> g = qry(1, n, j + 1, u - 1, 1);
        if (a[j] - g.fi <= d && g.se - a[j] <= d)
        {
            while (u <= n && abs(a[j] - a[u]) <= d)
                ++u;
        }
        ++j;
    }

    return (u == n + 1);
}

void ka()
{
    cin >> n >> s1 >> s2;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

void gen()
{
    n = 5;
    s1 = rnf() % 10, s2 = rnf() % 10;
    for (int i = 1; i <= n; ++i)
        a[i] = rnf() % 10;
}

int solv()
{

    bil(1, n, 1);

    int l = abs(s1 - s2), r = 1000000000;
    int ans;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    cout << ans << "\n";
    return ans;
}

int solv0()
{
    int ans = INF;
    for (int x = 0; x < (1 << n); ++x)
    {
        int u1 = s1, u2 = s2;
        int yans = abs(s1 - s2);
        for (int i = 1; i <= n; ++i)
        {
            if (!(x & (1 << (i - 1))))
                u1 = a[i];
            else
                u2 = a[i];
            yans = max(yans, abs(u1 - u2));
        }
        ans = min(ans, yans);
    }
    return ans;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*int st = 100;
    while (st--)
    {
        gen();
        if (solv() != solv0())
        {
            cout << n << ' ' << s1 << ' ' << s2 << "\n";
            for (int i = 1; i <= n; ++i)
                cout << a[i] << ' ';
            cout << "\n";
            cout << "Incorrect: " << solv() << "\n";
            cout << "Correct: " << solv0() << "\n";
            return 0;
        }
    }
    return 0;*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        ka();
        solv();
    }
    return 0;
}