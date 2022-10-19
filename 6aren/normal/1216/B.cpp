#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int n;
pair<int, int> a[1005];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].fi;
		a[i].se = i;
	}
	sort(a + 1, a + n+ 1);
	int res = 0;
	for (int i = n; i >= 1; i--) {
		res += a[i].fi * (n - i) + 1;
	}
	cout << res << endl;
	for (int i = n; i >= 1; i--) {
		cout << a[i].se << ' ';
	}
	return 0;
}