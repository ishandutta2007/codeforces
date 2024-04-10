#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool a[10];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		char c;
		cin >> c;
		if (c == 'L') {
			int i = 0;
			while (a[i])
				++i;
			a[i] = 1;
		} else if(c=='R') {
			int i = 9;
			while(a[i])
				--i;
			a[i] = 1;
		} else {
			a[c-'0'] = 0;
		}
	}
	for(bool &x:a)
		cout << x;

	return 0;
}