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

int n, k;
ll b[N];

ll s[N * 4], d[N * 4];

void ubd(int tl, int tr, int l, int r, ll ss, ll dd, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        s[pos] += ss;
        d[pos] += dd;
        return;
    }
    int m = (tl + tr) / 2;
    if (r <= m)
        ubd(tl, m, l, r, ss, dd, pos * 2);
    else if (l > m)
        ubd(m + 1, tr, l, r, ss, dd, pos * 2 + 1);
    else
    {
        ubd(tl, m, l, m, ss, dd, pos * 2);
        ubd(m + 1, tr, m + 1, r, ss + (m - l + 1) * dd, dd, pos * 2 + 1);
    }
}

ll qry(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return s[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return s[pos] + (x - tl) * d[pos] + qry(tl, m, x, pos * 2);
    else
        return s[pos] + (x - tl) * d[pos] + qry(m + 1, tr, x, pos * 2 + 1);
}

void solv()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> b[i];

    ll ans = 0;
    for (int i = n; i >= 1; --i)
    {
        ll a = qry(1, n, i, 1);
        if (a >= b[i])
            continue;

        int l = max(1, i - k + 1);
        int r = l + k - 1;
        int u = (i - l + 1);

        ll q = (b[i] - a) / u;
        if ((b[i] - a) % u != 0)
            ++q;

        ans += q;
        ubd(1, n, l, r, q, q, 1);
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