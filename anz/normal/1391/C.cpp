#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
const ll MOD = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	ll ans = 1;
	for (ll i = 1; i <= n; i++) ans = ans * i % MOD;

	ll minus = 1;
	for (int i = 0; i < n - 1; i++) minus = minus * 2 % MOD;

	ans = (ans + MOD - minus) % MOD;
	cout << ans;
}