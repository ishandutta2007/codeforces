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
const int N = 600005, S = 500;

int n, q, k;
int a[N];

const int m = 20;
int minu[N][20];
int u[N];
void pre()
{
    for (int i = 1; i <= n; ++i)
    {
        minu[i][0] = a[i];
        u[i] = 0;
        for (int j = 1; i - (1 << j) + 1 >= 1; ++j)
        {
            minu[i][j] = min(minu[i][j - 1], minu[i - (1 << (j - 1))][j - 1]);
            u[i] = j;
        }
    }
}

int qry(int l, int r)
{
    return min(minu[r][u[r - l + 1]], minu[l + (1 << u[r - l + 1]) - 1][u[r - l + 1]]);
}

ll qry0(int l, int r)
{
    ll ans = 0;
    for (int i = l; i <= r; i += k)
        ans += qry(l, i);
    return ans;
}

vector<pair<int, int> > v[N];

int aa[N];
ll gg[N];
vector<int> s[N];

ll ans[N];

void solv()
{
    cin >> n >> q >> k;
    for (int i = 1; i <= n; ++i)
    {
        a[i] = rnf() % 10 + 1;
        cin >> a[i];
    }

    pre();

    /*if (k >= S)
    {
        while (q--)
        {
            int l, r;
            cin >> l >> r;

            ll ans = 0;
            for (int i = l; i <= r; i += k)
                ans += qry(l, i);

            cout << ans << "\n";
        }
        return;
    }*/

    for (int i = 1; i <= q; ++i)
    {
        int l = rnf() % n + 1, r = rnf() % n + 1;
        if (l > r)
            swap(l, r);
        cin >> l >> r;

        v[l].push_back(m_p(r, i));
    }

    n += k;

    for (int i = n; i >= 1; --i)
    {
        for (int j = 0; j < sz(v[i]); ++j)
        {
            if (v[i][j].fi - i + 1 <= k)
            {
                ans[v[i][j].se] = a[i];
                continue;
            }
            assert(!s[i % k].empty());

            int l = 0, r = sz(s[i % k]) - 1;
            int u = -1;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (s[i % k][m] > v[i][j].fi)
                {
                    u = m;
                    l = m + 1;
                }
                else
                    r = m - 1;
            }

            assert(u != -1);
                ans[v[i][j].se] = a[i] + gg[s[i % k].back()] - gg[s[i % k][u]] -
                                    aa[s[i % k][u + 1]] * 1LL * ((s[i % k][u] - v[i][j].fi - 1) / k);

            /*if (ans[v[i][j].se] != qry0(i, v[i][j].fi))
            {
                cout << "WA\n";
                cout << i << ' ' << v[i][j].fi << "\n";
                return;
            }*/
        }

        if (i - k >= 1)
        {
            aa[i] = qry(i - k, i);
            while (!s[i % k].empty() && aa[s[i % k].back()] >= aa[i])
            {
                s[i % k].pop_back();
            }

            if (s[i % k].empty())
            {
                gg[i] = ((n - i) / k + 1) * 1LL * aa[i];
            }
            else
            {
                gg[i] = ((s[i % k].back() - i - 1) / k + 1) * 1LL * aa[i] + gg[s[i % k].back()];
            }
            s[i % k].push_back(i);
        }
    }

    for (int i = 1; i <= q; ++i)
        cout << ans[i] << "\n";
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