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
		int st, in, ex;
		cin >> st >> in >> ex;
		int min_a = ((in - st + 1) + ex + 1) / 2;
		min_a = max(min_a, 0);
		cout << max(0, ex - min_a + 1) << endl;
	}
}