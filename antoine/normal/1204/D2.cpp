#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s;
	cin >> s;

	int cnt = 0;
	for (int i = (int) s.size() - 1; i >= 0; --i) {
		if(s[i] == '0')
			++cnt;
		else if(--cnt < 0) {
			cnt = 0;
			s[i] = '0';
		}
	}
	cout << s;
	return 0;
}