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

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
ll a[N];

ll b[N];

ll t[N * 4];

void bil(int tl, int tr, int pos)
{
    if (tl == tr)
    {
        t[pos] = b[tl];
        return;
    }
    int m = (tl + tr) / 2;
    bil(tl, m, pos * 2);
    bil(m + 1, tr, pos * 2 + 1);
    t[pos] = gcd(t[pos * 2], t[pos * 2 + 1]);
}

ll y;
int yans;
bool qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return false;
    if (tl == l && tr == r)
    {
        if (gcd(y, t[pos]) != 1)
        {
            yans += (r - l + 1);
            y = gcd(y, t[pos]);
            return false;
        }
        if (tl == tr)
            return true;
        int m = (tl + tr) / 2;
        if (qry(tl, m, l, m, pos * 2))
            return true;
        if (qry(m + 1, tr, m + 1, r, pos * 2 + 1))
            return true;
        assert(false);
    }
    int m = (tl + tr) / 2;
    if (qry(tl, m, l, min(m, r), pos * 2))
        return true;
    if (qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1))
        return true;
    return false;
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    if (n == 1)
    {
        cout << "1\n";
        return;
    }

    for (int i = 1; i < n; ++i)
    {
        b[i] = (a[i + 1] - a[i]);
        if (b[i] < 0)
            b[i] *= -1;
    }

    bil(1, n - 1, 1);

    int ans = 1;
    for (int i = 1; i < n; ++i)
    {
        yans = 1;
        y = 0;
        qry(1, n - 1, i, n - 1, 1);
        ans = max(ans, yans);
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
    cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}