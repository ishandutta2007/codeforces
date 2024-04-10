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
const int N = 1000005;

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

pair<ll, ll> gcdd(ll a, ll b)
{
    if (a == 0)
        return m_p(0, 1);
    pair<ll, ll> u = gcdd(b % a, a);
    return m_p(u.se - u.fi * (b / a), u.fi);
}

int n, m;
ll k;
int a[N];
int b[N];

int ua[N], ub[N];
ll x[N];
void pre()
{
    ll g = gcd(n, m);
    ll l = n / g * m;
    pair<ll, ll> u = gcdd(n, m);

    ll q = 0;
    for (int i = 1; i <= 2 * max(n, m); ++i)
    {
        if (!ua[i] || !ub[i])
            continue;
        if ((ua[i] - ub[i]) % g != 0)
            continue;
        --ua[i];
        --ub[i];
        x[i] = ((n / g) * u.fi) % l * ub[i] + ((m / g) * u.se) % l * ua[i];
        x[i] %= l;
        if (x[i] < 0)
            x[i] += l;

        assert(x[i] % n == ua[i] && x[i] % m == ub[i]);

        ++ua[i];
        ++ub[i];
    }
}

bool stg(ll d)
{
    ll g = gcd(n, m);
    ll l = n / g * m;

    ll q = 0;
    ll dbl = d / l;
    ll dml = d % l;
    for (int i = 1; i <= 2 * max(n, m); ++i)
    {
        if (!ua[i] || !ub[i])
            continue;
        if ((ua[i] - ub[i]) % g != 0)
            continue;

        q += dbl;
        if (x[i] < dml)
            ++q;
    }

    return (d - q) >= k;
}

void solv()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= m; ++i)
        cin >> b[i];

    for (int i = 1; i <= n; ++i)
        ua[a[i]] = i;
    for (int i = 1; i <= m; ++i)
        ub[b[i]] = i;

    pre();

    ll l = k, r = max(n, m) * k;
    ll ans;
    while (l <= r)
    {
        ll m = (l + r) / 2;
        if (stg(m))
        {
            ans = m;
            r = m - 1;
        }
        else
            l = m + 1;
    }

    cout << ans << endl;
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    int tt = 1;
    //scanf("%d", &tt);
    while (tt--)
        solv();
    return 0;
}