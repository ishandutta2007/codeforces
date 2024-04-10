#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int int64_t
#define all(x) begin(x), end(x)

const int mod = 998244353;

int add(int a, int b) {
	return (a + b) % mod;
}
int sub(int a, int b) {
	return (a + mod - b) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

const int maxn = 1e5 + 42;

int get(int n, int a, int b) {
	n -= 2;
	
}

vector<string> get(int h, int w) {
	vector<string> ans(h, string(w, '0'));
	
	for(int i = 0; i < h - (h % 2 == 0); i++) {
		ans[i][0] = ans[h % 2 ? i : h - i - 1][w - 1] = '0' + ((i % 2) ^ (h % 2));
	}
	for(int i = 0; i < w - (w % 2 == 0); i++) {
		ans[0][w % 2 ? i : w - i - 1] = ans[h - 1][i] = '0' + ((i % 2) ^ (w % 2));
	}
	return ans;
}

void solve() {
	int h, w;
	cin >> h >> w;
	bool rev = h % 2 == 0 && w % 2 == 1;
	auto ans = (rev ? get(w, h) : get(h, w));
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			cout << (!rev ? ans[i][j] : ans[j][i]);
			if(j + 1 == w) {
				cout << "\n";
			}
		}
	}
	cout << "\n";
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}