#include <bits/stdc++.h>
using namespace std;

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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> lens;
		vector<int> cnt(2);
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			int m = s.size();
			lens.push_back(m / 2);
			for (int j = 0; j < m; j++) {
				cnt[s[j] - '0']++;
			}
		}
		sort(lens.begin(), lens.end());
		int cntt = cnt[0] / 2 + cnt[1] / 2;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (lens[i] <= cntt) {
				ans++;
				cntt -= lens[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}