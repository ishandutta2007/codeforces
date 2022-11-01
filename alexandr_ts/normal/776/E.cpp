#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 1;
const int M = 1e3 + 2;
const ll INF = 2e9 + 7;
const ll MOD = 1000 * 1000 * 1000 + 7;
const ll MAX = 1e15;
const ld EPS = 1e-10;

ll f(ll n) {
	ll ans = n;

	for (ll i = 2; i*i <= n; i++)
		if (n % i == 0) {
			while (n % i == 0) n /= i;
			ans -= ans / i;
		}
	if (n > 1)
		ans -= ans / n;
	return ans;
}

int main() {
    //freopen("a.in", "r", stdin);
    //ios_base::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll cur = n;
    //cout << f(7) << endl;
    for (ll i = 1; i <= (k + 1) / 2; i++) {
        if (cur == 1) break;
        cur = f(cur);
    }
    cout << cur % MOD;
}