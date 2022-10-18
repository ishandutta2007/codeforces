#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mod = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % mod;
}

int mul(int a,int b) {
	return a * b % mod;
}

int bpow(int x, int n) {
	return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}

int inv(int x) {
	return bpow(x, mod - 2);
}

int sub(int a, int b) {
	return (a + mod - b) % mod;
}

int dv(int a, int b) {
	return mul(a, inv(b));
}

const int maxn = 5e5 + 42;

#define all(x) begin(x), end(x)

int n;

vector<int> ask(int v) {
	cout << "? " << v + 1 << endl;
	vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		cin >> ans[i];
	}
	return ans;
}

void solve() {
	cin >> n;
	auto r1 = ask(0);
	int cnt[2] = {0, 0};
	for(int i = 1; i < n; i++) {
		cnt[r1[i] % 2]++;
	}
	int type = cnt[1] < cnt[0];
	vector<pair<int, int>> ans;
	for(int i = 1; i < n; i++) {
		if(r1[i] % 2 == type) {
			auto r2 = ask(i);
			for(int j = 0; j < n; j++) {
				if(r2[j] == 1) {
					ans.emplace_back(i, j);
				}
			}
		}
		if(type == 0 && r1[i] == 1) {
			ans.emplace_back(0, i);
		}
	}
	cout << "!" << endl;
	for(auto it: ans) {
		cout << it.first + 1 << ' ' << it.second + 1 << endl;
	}
	
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//ignore = freopen("input.txt", "r", stdin);
	int t;
	t = 1;//cin >> t;
	while(t--) {
		solve();
	}
}