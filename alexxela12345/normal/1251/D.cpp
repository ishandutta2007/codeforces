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
ostream &operator<<(ostream &out, pair<T, TT> &pp) {
	out << pp.first << " " << pp.second;
	return out;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int s;
		cin >> s;
		vector<vector<int>> arr(n, vector<int> (2));
		cin >> arr;
		sort(arr.begin(), arr.end());
		int l = arr[n / 2][0];
		int r = 1e9 + 228;
		while (r - l > 1) {
			int m = l + (r - l) / 2;
			vector<vector<int>> a1, a2, a12;
			for (int i = 0; i < n; i++) {
				if (arr[i][1] < m) {
					a1.push_back(arr[i]);
				} else if (arr[i][0] > m) {
					a2.push_back(arr[i]);
				} else {
					a12.push_back(arr[i]);
				}
			}
			int h1 = n / 2 - a1.size();
			int h2 = n / 2 - a2.size();
			h1 = max(0LL, h1);
			h2 = max(0LL, h2);
			if (h1 + h2 + 1 > a12.size()) {
				r = m;
				continue;
			}
			sort(a12.begin(), a12.end());
			int ss = 0;
			for (auto &el : a1) {
				ss += el[0];
			}
			for (int i = 0; i < n / 2 - (int) a1.size(); i++) {
				ss += a12[i][0];
			}
			for (int i = h1; i < a12.size(); i++) {
				ss += max(a12[i][0], m);
			}
			for (auto &el : a2) {
				ss += el[0];
			}
			if (ss <= s) {
				l = m;
			} else {
				r = m;
			}
		}
		cout << l << endl;
	}
	return 0;
}