#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int logn = 26;
const int maxn = 4e5 + 42;

int cnt[1 << logn];

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] <<= 1;
	}
	int ans = 0;
	for(int i = 0; i < logn; i++) {
		for(int j =	 i + 1; j < logn; j++) {
			for(int k = 0; k < n; k++) {
				cnt[(a[k] >> i) & ((1 << (j - i + 1)) - 1)] ^= 1;
			}
			for(int k = 0; k < n; k++) {
				int mask = (a[k] >> i) & ((1 << (j - i + 1)) - 1);
				cnt[mask] ^= 1;
				int tmask = mask ^ ((1 << (j - i)) - 2);
				if(cnt[tmask]) {
					ans ^= (1 << j) - (((mask & 1) ^ 1) << (i + 1));
				}
			}
		}
	}
	cout << ans / 2 << endl;
	return 0;
}