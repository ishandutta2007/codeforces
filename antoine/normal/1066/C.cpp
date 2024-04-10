#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;

int pos[(int) 2e5 + 999];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int l = 0, r = -1, q;
	cin >> q;
	while(q--) {
		char type;
		int x;
		cin >> type >> x;
		if(type == 'L')
			pos[x] = --l;
		else if(type == 'R')
			pos[x] = ++r;
		else {
			assert(type == '?');
			const int ans = min(pos[x] - l, r - pos[x]);
			cout << ans << '\n';
		}
	}
	return 0;
}