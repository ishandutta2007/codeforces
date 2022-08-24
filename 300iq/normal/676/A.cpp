#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fc first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
	ios_base::sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n;
	cin >> n;
	vector <int> a(n);
	int pm = 0, px = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > a[pm]) {
			pm = i;
		}
		if (a[i] < a[px]) {
			px = i;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				int nm = pm, nx = px;
				if (pm == i) {
					nm = j;
				}
				if (nx == j) {
					nx = i;
				}
				ans = max(ans, abs(nm - nx));
			}
		}
	}
	cout << ans << endl;
}