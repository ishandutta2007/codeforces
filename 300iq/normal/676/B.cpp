#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define int long long
#define fc first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

double p[17][4096];

main() {
	ios_base::sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, t;
	cin >> n >> t;
	while (t--) {
		p[0][0]++;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (p[i][j] > 1) {
					p[i + 1][j] += (p[i][j] - 1) / 2;
					p[i + 1][j + 1] += (p[i][j] - 1) / 2;
					p[i][j] = 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			ans += (p[i][j] >= 1);
		}
	}
	cout << ans << endl;
}