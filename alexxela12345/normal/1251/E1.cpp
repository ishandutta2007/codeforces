#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e15;

typedef long long ll;
typedef long double ldb;

int add(int a, int b) {
	if (a == INF) {
		return a;
	}
	if (b == INF) {
		return b;
	}
	return a + b;
}

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
		vector<pair<int, int>> arr(n);
		cin >> arr;
		sort(arr.begin(), arr.end());
		vector<int> c(n), p(n);
		for (int i = 0; i < n; i++) {
			c[i] = arr[i].first;
			p[i] = arr[i].second;
		}
		vector<vector<int>> min_sum(n, vector<int> (n));
		for (int i = n - 1; i >= 0; i--) {
			vector<int> kek;
			for (int j = i + 1; j < n; j++) {
				kek.push_back(p[j]);
			}
			sort(kek.begin(), kek.end());
			for (int j = 0; j < n; j++) {
				if (j == 0) {
					min_sum[i][j] = 0;
				} else if ((int) kek.size() < j) {
					min_sum[i][j] = INF;
				} else {
					min_sum[i][j] = add(min_sum[i][j - 1], kek[j - 1]);
				}
			}
		}
		vector<vector<int>> dp(n, vector<int> (n));
		for (int j = 0; j < n; j++) {
			if (c[0] <= j) {
				dp[0][j] = 0;
			} else {
				dp[0][j] = p[0];
			}
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = add(dp[i - 1][j + 1], p[i]);
				if (c[i] <= i + j) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j]);
				}
			}
		}
		cout << dp[n - 1][0] << endl;
	}
	return 0;
}