#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector <ll> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (ll i = 3; i * i / 2 + 1 <= 1e9; i += 2)
	{
		ans.push_back(i * i / 2 + 1);
	}

	int t; cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		cout << upper_bound(ans.begin(), ans.end(), n) - ans.begin() << '\n';
	}
}