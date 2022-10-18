#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define int int64_t

using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 42;



signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int a, b;
	cin >> a >> b;
	int mn = -1, mx = -1;
	for(int s = 0; s < k; s++) {
		if(min(s, k - s) == a) {
			for(int l = 0; l < k; l++) {
				if(min((s + l) % k, k - (s + l) % k) == b) {
					for(int t = 0; t < n; t++) {
						int L = l + t * k;
						int g = __gcd(L, n * k);
						if(mn == -1 || n * k / g < mn) {
							mn = n * k / g;
						}
						if(mx == -1 || n * k / g > mx) {
							mx = n * k / g;
						}
					}
					
				}
			}
		}
	}
	cout << mn << ' ' << mx << endl;
	return 0;
}