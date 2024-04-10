#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 998244353;
const int maxn = 1e5 + 42;

int add(int a, int b) {
	return (a + b) % mod;
}
int mul(int a, int b) {
	return a * b % mod;
}
int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2)  : 1;
}
int inv(int x) {
	return bpow(x, mod - 2);
}

void solve() {
	int n;
	cin >> n;
	string color = "blue";
	bool lock = false;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if(s == "lock") {
			lock = true;
		} else if(s == "unlock") {
			lock = false;
		} else if(!lock) {
			color = s;
		}
	}
	cout << color << endl;
}

signed main() {
	//ignore = freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
}