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
const ll INF = 4000000009000000009;

int n, q;
int x[N], w[N];

ll F(int i, int j)
{
    return (abs(x[i] - x[j]) * 1LL * (w[i] + w[j]));
}

ll qry0(int l, int r)
{
    ll ans = INF;
    for (int i = l; i <= r; ++i)
    {
        for (int j = i + 1; j <= r; ++j)
        {
            ans = min(ans, F(i, j));
        }
    }
    return ans;
}

vector<pair<int, int> > v[N];

ll t[N];
void ubd(int x, ll y)
{
    while (x <= n)
    {
        t[x] = min(t[x], y);
        x += (x & (-x));
    }
}

ll qry(int x)
{
    ll ans = INF;
    while (x)
    {
        ans = min(ans, t[x]);
        x -= (x & (-x));
    }
    return ans;
}

ll ans[N];

void solv()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> w[i];

    for (int i = 1; i <= q; ++i)
    {
        int l, r;
        cin >> l >> r;
        v[r].push_back(m_p(l, i));
    }

    for (int i = 1; i <= n; ++i)
        t[i] = INF;
    stack<int> s;
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && w[i] < w[s.top()])
        {
            ubd(n - s.top() + 1, F(i, s.top()));
            s.pop();
        }
        if (!s.empty())
            ubd(n - s.top() + 1, F(i, s.top()));
        s.push(i);

        for (int j = 0; j < sz(v[i]); ++j)
        {
            ans[v[i][j].se] = qry(n - v[i][j].fi + 1);
            //assert(ans[v[i][j].se] == qry0(v[i][j].fi, i));
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