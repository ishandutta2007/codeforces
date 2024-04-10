#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;
#define int long long

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt = {1};
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            cnt.back()++;
        } else {
            cnt.push_back(1);
        }
    }
    int m = cnt.size();
    int ans = n * (n - 1) / 2;
    for (int i = 0; i < m; i++) {
        if (i) {
            ans -= cnt[i - 1];
        }
        if (i != m - 1) {
            ans -= cnt[i + 1];
        }
    }
    ans += cnt.size() - 1;
    cout << ans << endl;
}