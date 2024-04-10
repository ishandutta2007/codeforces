#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void getDivisorsHelper(int i, ll curr, const vector<pair<ll, int>> &v, vector<ll> &res) {
	if (i == (int) v.size())
		res.push_back(curr);
	else {
		for (int j = 0; j <= v[i].second; ++j) {
			getDivisorsHelper(i + 1, curr, v, res);
			curr *= v[i].first;
		}
	}
}

vector<ll> getDivisors(ll x) {
	vector<pair<ll, int>> v;
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			v.emplace_back(i, 1);
			for (x /= i; x % i == 0; x /= i)
				v.back().second++;
		}
	if (x != 1)
		v.emplace_back(x, 1);
	vector<ll> res;
	getDivisorsHelper(0, 1, v, res);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n;
	cin >> n;

	set<ll> s;
	for (const ll d : getDivisors(n)) {
		const ll cnt = n / d;
		s.insert(cnt + cnt*(cnt-1)/2 * d);
	}

	for (const ll x : s)
		cout << x << ' ';
	return 0;
}