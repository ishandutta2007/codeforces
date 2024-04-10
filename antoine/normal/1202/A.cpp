#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
	string s, t;
	cin >> s >> t;

	int i = 0;
	while (*(t.rbegin() + i) != '1')
		++i;
	int j = i;
	while (*(s.rbegin() + j) != '1')
		++j;
	cout << j - i << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
		f();
	return 0;
}