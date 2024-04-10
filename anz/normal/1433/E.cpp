#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n; cin >> n;
	n /= 2; n--;

	ll ans = 1;
	for (ll i = 1; i <= 2 * n + 1; i++) ans *= i;
	ans /= n + 1;

	cout << ans;
}