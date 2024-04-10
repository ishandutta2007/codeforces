#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;

string s;
vector < char > v;
vector < int > sz;
int main() {
	cin >> s;
	s = '0' + s;
	int pnt = 1;
	while (pnt < s.size()) {
		v.push_back(s[pnt]);
		int tmp = pnt;
		while (pnt < s.size() && s[pnt] == s[tmp])
			pnt++;
		sz.push_back(pnt - tmp);
	}
	if (sz.size() % 2 == 0) {
		cout << 0;
		return 0;
	}
	int l = 0, r = v.size() - 1;
	while (r > l) {
		if (v[l] != v[r]) {
			cout << 0;
			return 0;
		}
		if (sz[l] + sz[r] < 3) {
			cout << 0;
			return 0;
		}
		l++;
		r--;
	}
	if (sz[l] + 1 < 3) {
		cout << 0;
		return 0;
	}
	cout << sz[l] + 1;

}