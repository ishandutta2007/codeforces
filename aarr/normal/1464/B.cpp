#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5;

int ps[N];
vector <int> vec;

int main() {
	ios :: sync_with_stdio(false);
	string s;
	cin >> s;
	long long x, y;
	cin >> x >> y;
	long long ans = 0, c = 0, q = 0;
	if (x > y) {
		swap(x, y);
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				s[i] = '1';
			}
			else if (s[i] == '1') {
				s[i] = '0';
			}
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (i) {
			ps[i] += ps[i - 1];
		}
		if (s[i] == '1') {
			q += x * (i - ps[i - 1]);
			ps[i]++;
		}
		if (s[i] == '?') {
			vec.push_back(i);
			q += y * ps[i - 1];
		}
		if (s[i] == '0') {
			q += y * ps[i - 1];
		}
	}
	reverse(vec.begin(), vec.end());
	ans = q;
//	cout << "72 " << q << endl;
	for (auto i : vec) {
		if (i) {
			q += x * (i - ps[i]);
			q -= y * ps[i];
		}
		q += y * (s.size() - i - 1 - ps[s.size() - 1] + ps[i] - c);
		q -= x * (ps[s.size() - 1] - ps[i] + c);
		ans = min(ans, q);
		c++;
	}
	cout << ans;
	return 0;
}