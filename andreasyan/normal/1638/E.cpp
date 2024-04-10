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

int n, q;
int c0[N];

vector<int> t[N];
vector<ll> p[N];

ll qryy(int t0, int c)
{
    if (t[c].empty())
        return 0;

    int i = lower_bound(all(t[c]), t0) - t[c].begin() - 1;

    ll ans = p[c].back();
    if (i >= 0)
        ans -= p[c][i];

    return ans;
}

int u[N * 4];
ll s[N * 4];

void ubd(int tl, int tr, int l, int r, int y, int pos)
{
    if (l > r)
        return;
    if (tl == l && tr == r)
    {
        if (u[pos] != -1)
        {
            s[pos] += qryy(u[pos], c0[u[pos]]);
            u[pos] = y;
            return;
        }
    }

    if (u[pos] != -1)
        u[pos * 2] = u[pos * 2 + 1] = u[pos];

    int m = (tl + tr) / 2;
    ubd(tl, m, l, min(m, r), y, pos * 2);
    ubd(m + 1, tr, max(m + 1, l), r, y, pos * 2 + 1);

    if (u[pos * 2] == u[pos * 2 + 1])
        u[pos] = u[pos * 2];
    else
        u[pos] = -1;
}

ll qry(int tl, int tr, int x, int pos)
{
    if (u[pos] != -1)
        return qryy(u[pos], c0[u[pos]]);
    int m = (tl + tr) / 2;
    if (x <= m)
        return qry(tl, m, x, pos * 2);
    return qry(m + 1, tr, x, pos * 2 + 1);
}

ll qrys(int tl, int tr, int x, int pos)
{
    if (tl == tr)
        return s[pos];
    int m = (tl + tr) / 2;
    if (x <= m)
        return s[pos] + qrys(tl, m, x, pos * 2);
    return s[pos] + qrys(m + 1, tr, x, pos * 2 + 1);
}

void solv()
{
    cin >> n >> q;

    c0[0] = 1;
    for (int i = 1; i <= q; ++i)
    {
        char ty[10];
        cin >> ty;

        if (ty[0] == 'A')
        {
            int c, x;
            cin >> c >> x;

            t[c].push_back(i);
            if (p[c].empty())
                p[c].push_back(x);
            else
                p[c].push_back(p[c].back() + x);
        }
        else if (ty[0] == 'C')
        {
            int l, r;
            cin >> l >> r >> c0[i];

            ubd(1, n, l, r, i, 1);
        }
        else if (ty[0] == 'Q')
        {
            int x;
            cin >> x;

            cout << qrys(1, n, x, 1) + qry(1, n, x, 1) << "\n";
        }
        else
            assert(false);
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