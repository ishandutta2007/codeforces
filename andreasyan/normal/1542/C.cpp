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
const ll M = 1000000007;

ll gcd(ll x, ll y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

const int m = 43;
ll u[m];

void solv()
{
    ll n;
    cin >> n;

    u[1] = 1;
    for (ll i = 2; i < m; ++i)
    {
        u[i] = u[i - 1] / gcd(u[i - 1], i) * i;
    }

    ll ans = 0;
    for (ll i = m - 2; i >= 1; --i)
    {
        ll q = n / u[i] - n / u[i + 1];
        ans = (ans + q * (i + 1)) % M;
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