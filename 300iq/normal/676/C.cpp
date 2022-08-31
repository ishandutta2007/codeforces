#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fc first
#define sc second
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

double at[11][11];

int main() {
	ios_base::sync_with_stdio(0);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int ans = 0;
	for (char c = 'a'; c <= 'b'; c++) {
		int j = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			while (j < n) {
				cnt += (s[j] != c);
				if (cnt > k) {
					cnt -= (s[j] != c);
					break;
				}
				j++;
			}
			ans = max(ans, j - i);
			cnt -= (s[i] != c);
		}
	}
	cout << ans << endl;
}