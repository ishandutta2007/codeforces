#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void getDivisorsHelper(int i, ll curr, const vector<pair<ll, int>> &v, vector<ll> &res) {
	if (i == v.size())
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
	for (ll i = 2; i*i <= x; ++i)
		if (x%i == 0) {
			v.emplace_back(i, 1);
			for (x /= i; x%i == 0; x /= i)
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

	ll x;
	cin >> x;

	cout << getDivisors(x).size();
	return 0;
}