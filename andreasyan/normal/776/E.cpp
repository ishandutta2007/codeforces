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

int tf(int n)
{
    if (n == 1)
        return 1;

    int ans = 0;
    for (int i = 1; i < n; ++i)
    {
        if (gcd(i, n - i) == 1)
            ++ans;
    }
    return ans;
}

int tg(int n)
{
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (n % i == 0)
            ans += tf(i);
    }
    return ans;
}

ll f(ll n)
{
	ll result = n;
	for (ll i = 2; i * i <= n; ++i)
		if (n % i == 0)
        {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

void solv()
{
    ll n, k;
    cin >> n >> k;

    k = (k + 1) / 2;

    for (ll i = 1; i <= k; ++i)
    {
        n = f(n);
        if (n == 1)
            break;
    }

    cout << n % M << "\n";
}

int main()
{
    #ifdef SOMETHING
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #endif // SOMETHING
    ios_base::sync_with_stdio(false), cin.tie(0);

    /*for (int n = 1; n <= 40; ++n)
    {
        for (int m = 1; m <= 40; ++m)
        {
            if (gcd(n, m) == 1)
                assert(tf(n) * tf(m) == tf(n * m));
        }
    }
    for (int n = 3; n <= 1000; n *= 3)
        assert(tf(n) == n - (n / 3));

    for (int n = 1; n <= 100; ++n)
        assert(n == tg(n));*/

    int tt = 1;
    //cin >> tt;
    while (tt--)
    {
        solv();
    }
    return 0;
}