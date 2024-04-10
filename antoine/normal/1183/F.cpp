#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int Mx = (int) 2e5 + 9;

vector<pair<ll, int>> getFact(ll x) {
	assert(x > 0);
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

ll f() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = (int) a.size();

	const int K = 170;

	int ans = a.back();

	for (int i = n - 1; i >= 0; --i)
		for (int j = i - 1; j >= 0; --j)
			if (a[i] % a[j]) {
				ans = max(ans, a[i] + a[j]);
				break;
			}

	for (int i = n - 1; i >= 2 && a[i] + a[i - 1] + a[i - 2] > ans; --i)
		for (int j = i - 1; j >= 1 && a[i] + a[j] + a[j - 1] > ans; --j)
			if (a[i] % a[j])
				for (int k = j - 1; k >= 0; --k)
					if (a[i] % a[k] && a[j] % a[k]) {
						ans = max(ans, a[i] + a[j] + a[k]);
						break;
					}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--)
		cout << f() << '\n';
	return 0;
}