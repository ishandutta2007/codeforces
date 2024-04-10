#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
//using namespace __gnu_pbds;

//typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define all(x) begin(x), end(x)

//#define int int64_t
const int mod = 31607;

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


void sos(int *in, int n) {
	for(int i = 1; i < n; i *= 2) {
		for(int j = 0; j < n; j += 2 * i) {
			for(int k = 0; k < i; k++) {
				in[j + k + i] += in[j + k];
				if(in[j + k + i] >= mod) {
					in[j + k + i] -= mod;
				}
			}
		}
	}
}

void desos(int *in, int n) {
	for(int i = 1; i < n; i *= 2) {
		for(int j = 0; j < n; j += 2 * i) {
			for(int k = 0; k < i; k++) {
				in[j + k + i] -= in[j + k];
				if(in[j + k + i] < 0) {
					in[j + k + i] += mod;
				}
			}
		}
	}
}

const int maxn = 1 << 23;
int ans[maxn];
int prod[maxn];

void solve() {
	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[i][j] = mul(a[i][j], inv(10000));
		}
	}
	const int sz = 1 << (n + 2);
	fill(ans, ans + sz, 1);
	for(int i = 0; i < n; i++) {
		memset(prod, 0, sizeof prod);
		prod[0] = 1;
		for(int j = 0; j < n; j++) {
			int t = 1 << j;
			for(int k = 0; k < t; k++) {
				prod[k + t] = mul(prod[k], mod + 1 - a[i][j]);
				prod[k] = mul(prod[k], a[i][j]);
			}
		}
		prod[0] = 0;
		for(int msk = 0; msk < (1 << n); msk++) {
			int nmsk = msk | (((msk >> i) & 1) << n) | (((msk >> (n - i - 1)) & 1) << (n + 1));
			swap(prod[nmsk], prod[msk]);
		}
		sos(prod, sz);
		for(int i = 0; i < sz; i++) {
			ans[i] = (ans[i] * (prod[i] % mod)) % mod;
		}
	}
	desos(ans, sz);
	cout << (mod + 1 - (ans[sz - 1] % mod)) % mod << "\n";
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}