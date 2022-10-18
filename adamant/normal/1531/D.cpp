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
	string a[n + 2];
	a[0] = "unlock";
	set<int> locks, unlocks, cols;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] == "lock") {
			locks.insert(i);
		} else if(a[i] != "unlock") {
			cols.insert(i);
			if(a[i - 1] == "unlock") {
				unlocks.insert(i - 1);
			}
		}
	}
	a[n + 1] = "lock";
	locks.insert(n + 1);
	auto get = [&]() -> string {
		auto it = unlocks.empty() ? begin(cols) : cols.upper_bound(*locks.upper_bound(*prev(end(unlocks))));
		if(it == begin(cols)) {
			return "blue";
		} else {
			return a[*prev(it)];
		}
	};
	cout << get() << "\n";
	int t;
	cin >> t;
	while(t--) {
		int i;
		string s;
		cin >> i >> s;
		unlocks.erase(i);
		locks.erase(i);
		cols.erase(i);
		a[i] = s;
		if(a[i] == "lock") {
			locks.insert(i);
		}
		if(a[i] == "unlock" && a[i + 1] != "lock" && a[i + 1] != "unlock") {
			unlocks.insert(i);
		}
		if(a[i] != "lock" && a[i] != "unlock") {
			cols.insert(i);
			if(a[i - 1] == "unlock") {
				unlocks.insert(i - 1);
			}
		} else {
			unlocks.erase(i - 1);
		}
		cout << get() << "\n";
	}
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