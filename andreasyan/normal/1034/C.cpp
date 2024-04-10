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
const int N = 1000006, M = 1000000007;

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int n;
int a[N];

vector<int> g[N];

ll s[N];
void dfs0(int x)
{
    s[x] = a[x];
    for (int i = 0; i < g[x].size(); ++i)
    {
        int h = g[x][i];
        dfs0(h);
        s[x] += s[h];
    }
}

void solv()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int x = 2; x <= n; ++x)
    {
        int p;
        cin >> p;
        g[p].push_back(x);
    }

    dfs0(1);

    vector<ll> p;
    vector<int> qp;
    ll x = s[1];
    for (ll i = 2; i * i <= x; ++i)
    {
        if (x % i == 0)
        {
            p.push_back(i);
            qp.push_back(0);
            while (x % i == 0)
            {
                x /= i;
                qp.back()++;
            }
        }
    }
    if (x > 1)
    {
        p.push_back(x);
        qp.push_back(1);
    }

    vector<ll> b;
    for (ll i = 1; i * i <= s[1]; ++i)
    {
        if (s[1] % i == 0)
        {
            b.push_back(i);
            if (i * i != s[1])
                b.push_back(s[1] / i);
        }
    }
    sort(all(b));

    vector<ll> q;
    q.assign(sz(b), 0);
    for (int x = 2; x <= n; ++x)
    {
        ll u = gcd(s[1], s[x]);
        q[lower_bound(all(b), u) - b.begin()]++;
    }

    for (int i = 0; i < sz(p); ++i)
    {
        for (int j = 0; j < sz(b); ++j)
        {
            ll x = b[j];
            while (x % p[i] == 0)
            {
                x /= p[i];
                q[lower_bound(all(b), x) - b.begin()] += q[j];
            }
        }
    }

    vector<ll> ab;
    for (int qq = 2; qq <= n; ++qq)
    {
        if (s[1] % qq == 0)
        {
            if (q[lower_bound(all(b), s[1] / qq) - b.begin()] == qq - 1)
            {
                ab.push_back(s[1] / qq);
            }
        }
    }

    vector<int> dp;
    dp.assign(sz(ab), 0);
    for (int i = sz(ab) - 1; i >= 0; --i)
    {
        dp[i] = 1;
        for (int j = i + 1; j < sz(ab); ++j)
        {
            if (ab[i] % ab[j] == 0)
                dp[i] = (dp[i] + dp[j]) % M;
        }
    }

    int ans = 1;
    for (int i = 0; i < sz(ab); ++i)
        ans = (ans + dp[i]) % M;

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