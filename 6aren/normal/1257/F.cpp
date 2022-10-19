#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int base = 70;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;

int n;

map<ii, int> x1, x2;
map<ii, bool> check;
vector<ii> res;
int a[105];
ii h[35];

ii Hash(vector<int> v) {
	ii res = {0, 0};
	for (auto u : v) {
		res.x = res.x * base + u;
		res.y = res.y * base + u;
		res.x %= MOD1;
		res.y %= MOD2;
	}
	return res;
}

main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//15bit left;
	for (int x = 0; x < (1 << 15); x++) {
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			int u = __builtin_popcountll((a[i] >> 15) ^ x);
			v.push_back(u);
		}
		ii ha = Hash(v);
		res.push_back(ha);
		x1[ha] = x;
	}
	//15bit right;
	for (int x = 0; x < (1 << 15); x++) {
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			int u = __builtin_popcountll((a[i] & ((1 << 15) - 1)) ^ x);
			v.push_back(u);
		}
		ii ha = Hash(v);
		check[ha] = 1;
		x2[ha] = x;
	}
	for (int i = 0; i <= 30; i++) {
		vector<int> v;
		for (int j = 1; j <= n; j++) {
			v.pb(i);
		}
		h[i] = Hash(v);
	}
	int ans = 2e9;
	for (auto u : res) {
		//cout << u << endl;
		for (int i = 0; i <= 30; i++) {
			ii v;
			v.x = (h[i].x - u.x + MOD1) % MOD1;
			v.y = (h[i].y - u.y + MOD2) % MOD2;
			if (check[v]) {
				//if (u == 0 && i == 2) cout << x1[u] << ' ' << x2[v] << endl;
				ans = min(ans, (x1[u] << 15) + x2[v]);
			} 
		}
	}
	if (ans == 2e9) {
		cout << -1;
	} else cout << ans;
	return 0;
}