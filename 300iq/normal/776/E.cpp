#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll phi (ll n) {
	ll result = n;
	for (ll i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#endif
    ll n, k;
    cin >> n >> k;
    for (ll i = 1; i <= k; i++)
    {
        if (i % 2)
        {
            n = phi(n);
        }
        else
        {
            continue;
        }
        if (n == 1)
        {
            break;
        }
    }
    cout << n % (1000000007) << endl;
}