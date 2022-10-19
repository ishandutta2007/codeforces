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

ll lca(ll x, ll y)
{
    return x * y / gcd(x, y);
}

vector<int> b[N + 5];
vector<pair<int, int> > v[N + 5];

int n;
int l[N + 5], r[N + 5];
ll ans[N + 5];

int bb[N + 5];
ll t[(N + 5) * 4];
void ubd(int tl, int tr, int x, int y, int pos)
{
    if (tl == tr)
    {
        t[pos] += y;
        return;
    }
    int m = (tl + tr) / 2;
    if (x <= m)
        ubd(tl, m, x, y, pos * 2);
    else
        ubd(m + 1, tr, x, y, pos * 2 + 1);
    t[pos] = t[pos * 2] + t[pos * 2 + 1];
}

ll qry(int tl, int tr, int l, int r, int pos)
{
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t[pos];
    int m = (tl + tr) / 2;
    return (qry(tl, m, l, min(m, r), pos * 2) +
            qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> l[i] >> r[i];
        v[l[i]].push_back(m_p(r[i], i));
    }

    for (int i = 1; i < N; ++i)
    {
        for (int j = i; j < N; j += i)
            b[j].push_back(i);
    }

    /*for (int i = 1; i < N; ++i)
    {
        ubd(1, N, i, (sz(b[i]) - 1) * (sz(b[i]) - 2) / 2, 1);
        bb[i] = sz(b[i]) - 1;
    }
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            ans[v[i][j].se] += qry(1, N, i, v[i][j].fi, 1);
        }
        for (int j = 2 * i; j < N; j += i)
        {
            --bb[j];
            ubd(1, N, j, -bb[j], 1);
        }
    }*/

    for (int i = 1; i <= n; ++i)
    {
        /*for (int x = l[i]; x <= r[i]; ++x)
        {
            for (int y = x + 1; y <= r[i]; ++y)
            {
                for (int z = y + 1; z <= r[i]; ++z)
                {
                    if (lca(x, lca(y, z)) < x + y + z)
                    {
                        if (lca(x, lca(y, z)) / z == 2)
                            cout << x << ' ' << y << ' ' << z << endl;
                    }
                }
            }
        }*/

        for (int j = l[i]; j <= r[i]; ++j)
        {
            int x = j;
            int y = 1;
            while (x % 2 == 0)
            {
                x /= 2;
                y *= 2;
            }
            for (int k1 = 0; k1 < sz(b[x]); ++k1)
            {
                if (l[i] > b[x][k1] * y * 2)
                    continue;
                for (int k2 = k1 + 1; k2 < sz(b[x]); ++k2)
                {
                    if (b[x][k2] * y * 2 < j && (b[x][k1] + b[x][k2]) * y * 2 > j)
                        ++ans[i];
                }
            }
            for (int k1 = 0; k1 < sz(b[x]); ++k1)
            {
                int t1 = b[x][k1] * y * 2;
                if (!(l[i] <= t1 && t1 < j))
                    continue;
                int l = 0, r = sz(b[j]) - 1;

                int l1 = 0, r1 = sz(b[j]) - 1;
                while (l1 <= r1)
                {
                    int m = (l1 + r1) / 2;
                    if (b[j][m] >= ::l[i])
                    {
                        l = m;
                        r1 = m - 1;
                    }
                    else
                        l1 = m + 1;
                }

                int u = sz(b[j]) - 1;
                while (l <= r)
                {
                    int m = (l + r) / 2;
                    if (t1 + b[j][m] > j)
                    {
                        u = m;
                        r = m - 1;
                    }
                    else
                        l = m + 1;
                }
                ans[i] += (sz(b[j]) - u - 1);
            }
            for (int k1 = 0; k1 < sz(b[j]) - 1; ++k1)
            {
                if (b[j][k1] < l[i])
                    continue;
                ans[i] += (sz(b[j]) - k1 - 2);
            }
        }

        cout << (r[i] - l[i] + 1) * 1LL * (r[i] - l[i]) * 1LL * (r[i] - l[i] - 1) / 6 - ans[i] << "\n";
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