#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll, int>> getFact(ll x) {
	vector<pair<ll, int>> v;
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			v.emplace_back(i, 1);
			for (x /= i; x % i == 0; x /= i)
				v.back().second++;
		}
	if (x != 1)
		v.emplace_back(x, 1);

	return v;
}

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

vector<ll> getDivisors(const ll x) {
	const vector<pair<ll, int>> v = getFact(x);
	vector<ll> res;
	getDivisorsHelper(0, 1, v, res);
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	map<int, int> occ;

	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		++occ[x];
	}

	int a = 0;
	for (const auto &e : occ)
		a = max(a, e.first);

	for (const ll d : getDivisors(a))
		if (!--occ[d])
			occ.erase(d);

	int b = 0;
	for (const auto &e : occ)
		b = max(b, e.first);

	cout << a << ' ' << b;
	return 0;
}