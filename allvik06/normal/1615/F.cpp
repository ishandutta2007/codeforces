#include <iostream> 
#include <vector>
#include <array>
 
using namespace std;
#define int long long
const int mod = 1e9 + 7;

inline int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

inline int mult(int a, int b) {
	return (a * b % mod + mod) % mod;
}

signed main() {
		if (1) {
		    ios_base::sync_with_stdio(false);
		    cin.tie(nullptr);
		    cout.tie(nullptr);
		}
	   int q;
	   cin >> q;
	   while (q--) {
	   	int n;
	   	string s, t;
	   	cin >> n >> s >> t;
	   	vector <int> dp(2 * n + 1), cnt(2 * n + 1), ok(2 * n + 1);
	   	auto dp1 = dp;
	   	auto cnt1 = cnt;
	   	auto ok1 = ok;
	   	cnt[n] = ok[n] = 1;
	   	for (int i = 0; i < n; ++i) {
	   		for (int d = 0; d <= 2 * n; ++d) {
	   			if (!ok[d]) continue;
	   			for (int p1 = 0; p1 < 2; ++p1) {
	   				if (s[i] == '0' + (p1 ^ 1)) continue;
	   				for (int p2 = 0; p2 < 2; ++p2) {
	   					if (t[i] == '0' + (p2 ^ 1)) continue;
	   					int v1 = (p1 ^ (i & 1) ^ 1);
	   					int v2 = (p2 ^ (i & 1) ^ 1);
	   				//	cout << v1 << " " << v2 << "\n";
	   					int nd = d + v1 - v2;
	   					cnt1[nd] = add(cnt1[nd], cnt[d]);
	   					dp1[nd] = add(dp1[nd], dp[d]);
	   					ok1[nd] = true;
	   					if (v1 == v2) continue;
	   					if (v1 == 1 && d >= n) dp1[nd] = add(dp1[nd], mult(-i, cnt[d]));
	   					else if (v1 == 1) dp1[nd] = add(dp1[nd], mult(i, cnt[d]));
	   					if (v2 == 1 && d > n) dp1[nd] = add(dp1[nd], mult(i, cnt[d]));
	   					else if (v2 == 1) dp1[nd] = add(dp1[nd], mult(-i, cnt[d]));
	   				}
	   			}
	   		}
	   		dp.swap(dp1);
	   		ok.swap(ok1);
	   		cnt.swap(cnt1);
	   		dp1.assign(2 * n + 1, 0);
	   		cnt1.assign(2 * n + 1, 0);
	   		ok1.assign(2 * n + 1, 0);
	   	}
	   	cout << dp[n] << "\n";
	   }
}