#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef long double ldb;

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
	for (auto &el : arr) {
		in >> el;
	}
	return in;
}


template<typename T, typename TT>
istream &operator>>(istream &in, pair<T, TT> &pp) {
	in >> pp.first >> pp.second;
	return in;
}

template<typename T>
ostream &operator<<(ostream &out, vector<T> &arr) {
	for (auto &el : arr) {
		out << el << " ";
	}
	return out;
}

template<typename T, typename TT>
ostream &operator<<(ostream &out, pair<T, TT> pp) {
	out << pp.first << " " << pp.second;
	return out;
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int min_ans = 1e18;
		vector<pair<int, int>> arr(n);
		cin >> arr;
		int max_el = -1e18;
		int max_diff = -1e18;
		for (int i = 0; i < n; i++) {
			max_el = max(max_el, arr[i].first);
			max_diff = max(max_diff, arr[i].first - arr[i].second);
		}
		x -= max_el;
		if (x <= 0) {
			cout << 1 << endl;
			continue;
		}
		if (max_diff <= 0) {
			cout << -1 << endl;
			continue;
		}
		int ans = 1 + (x + max_diff - 1) / max_diff;
		cout << ans << endl;
	}
}