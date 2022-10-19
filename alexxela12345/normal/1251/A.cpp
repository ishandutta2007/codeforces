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
		string s;
		cin >> s;
		int n = s.size() + 1;
		s.push_back('\n');
		char c = '\n';
		int cur_cnt = 0;
		set<char> ans;
		for (int i = 0; i < n; i++) {
			if (s[i] == c) {
				cur_cnt++;
			} else {
				if (cur_cnt % 2 == 1) {
					ans.insert(c);
				}
				cur_cnt = 1;
				c = s[i];
			}
		}
		for (auto el : ans) {
			cout << el;
		}
		cout << endl;
	}
	return 0;
}