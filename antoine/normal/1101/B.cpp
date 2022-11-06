#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void f(bool b) {
	if (b) {
		cout << -1;
		exit(0);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	int l = find(s.begin(), s.end(), '[') - s.begin();
	l = find(s.begin() + l, s.end(), ':') - s.begin() + 1;


	int r = find(s.rbegin(), s.rend(), ']') - s.rbegin();
	r = find(s.rbegin() + r, s.rend(), ':') - s.rbegin() + 1;
	r = (int)s.size() - 1 - r;

	cerr << l << ' ' << r << endl;
	f(r - l + 1 < 0);

	int ans = 4 + count(s.begin() + l, s.begin() + r + 1, '|');
	cout << ans;
	return 0;
}