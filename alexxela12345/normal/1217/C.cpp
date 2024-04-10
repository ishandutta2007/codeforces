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
ostream &operator<<(ostream &out, pair<T, TT> pp) {
	out << pp.first << " " << pp.second;
	return out;
}


int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.size();
		vector<int> pref(n + 1);
		for (int i = 1; i <= n; i++) {
			pref[i] = pref[i - 1] + (s[i - 1] == '1');
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int cur_num = 0;
			for (int len = 1; len <= i + 1 && len < 20; len++) {
				cur_num += (1 << (len - 1)) * (s[i - len + 1] == '1');
				if (s[i - len + 1] != '0' && i + 1 - cur_num >= 0 && pref[i - len + 1] - pref[i + 1 - cur_num] == 0) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
}