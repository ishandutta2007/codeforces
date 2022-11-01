#include <bits/stdc++.h> 

using namespace std;

string a, b;
vector <int> p;

int main (int argc, char const *argv[]) {
	cin >> a >> b;
	int pos = 0, sz = a.size();
	for (int i = 0; i < sz; ++i) {
		if (a[i] == '+') ++pos;
		else --pos;
	}
	int q = 0;
	for (int i = 0; i < sz; ++i) {
		if (b[i] == '?') {
			++q;
			p.push_back(i);
		}
	}
	int up = 0;
	for (int mask = 0; mask < 1 << q; ++mask) {
		string c = b;
		for (int i = 0; i < q; ++i) {
			if (mask & 1 << i) {
				c[p[i]] = '+';
			} else {
				c[p[i]] = '-';
			}
		}
		int now = 0;
		for (int i = 0; i < sz; ++i) {
			if (c[i] == '+') ++now;
			else --now;
		}
		if (now == pos) {
			++up;
		}
	}
	int down = 1 << q;
	double ans = up * 1.0/down;
	printf("%0.14f\n", ans);
    return 0;
}