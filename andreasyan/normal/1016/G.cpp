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
ll x, y;
ll a[N];

vector<ll> v;
vector<int> q;

int dp[(1 << 22)];

void solv()
{
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    ll u = y;
    for (int i = 2; i < 1000000; ++i)
    {
        if (u % i == 0)
        {
            v.push_back(i);
            while (u % i == 0)
            {
                u /= i;
            }
        }
    }
    {
        ll t = gcd(u, x);
        if (1 < t && t < u)
        {
            v.push_back(t);
            if (u / t != t)
                v.push_back(u / t);
            u = 1;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        ll t = gcd(u, a[i]);
        if (1 < t && t < u)
        {
            v.push_back(t);
            if (u / t != t)
                v.push_back(u / t);
            u = 1;
        }
    }
    if (u > 1)
        v.push_back(u);
    u = y;
    for (int i = 0; i < sz(v); ++i)
    {
        q.push_back(0);
        while (u % v[i] == 0)
        {
            ++q[i];
            u /= v[i];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % x == 0)
        {
            ll u = a[i] / x;
            u = gcd(u, y);

            int m = 0;
            for (int j = 0; j < sz(v); ++j)
            {
                if (u % v[j] == 0)
                    m |= (1 << j);
            }
            dp[m]++;
        }
    }

    for (int j = 0; j < sz(v); ++j)
    {
        for (int m = (1 << sz(v)) - 1; m >= 0; --m)
        {
            if ((m & (1 << j)))
                dp[m] += dp[(m ^ (1 << j))];
        }
    }

    ll ans = 0;
    for (int j = 1; j <= n; ++j)
    {
        if (y % a[j] == 0 && y % x == 0)
        {
            ll g = 1;
            ll u = y;
            while (1)
            {
                ll t = gcd(y / a[j], u);
                if (t == 1)
                    break;
                g *= t;
                u /= t;
            }

            g /= gcd(g, x);
            int m = 0;
            for (int j = 0; j < sz(v); ++j)
            {
                if (g % v[j] != 0)
                    m |= (1 << j);
            }
            ans += dp[m];
        }
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