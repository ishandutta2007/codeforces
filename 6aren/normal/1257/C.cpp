#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ii pair
#define x first
#define y second

int a[200005], app[200005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ntest;
	cin >> ntest;
	while (ntest--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			app[i] = 0;
		}
		int res = 1e9;
		for (int i = 1; i <= n; i++) {
			if (app[a[i]] != 0) {
				res = min(res, i - app[a[i]] + 1);
			}
			app[a[i]] = i;
		}
		if (res == 1e9) {
			cout << "-1\n";
		} else {
			cout << res << '\n';
		}
	}
	return 0;
}