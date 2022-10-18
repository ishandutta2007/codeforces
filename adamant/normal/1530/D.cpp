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

void solve() {
	int n;
	cin >> n;
	int a[n];
	vector<int> que[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		que[a[i]].push_back(i);
	}
	int b[n];
	set<pair<int, int>> ques;
	for(int i = 0; i < n; i++) {
		ques.insert({que[i].size(), i});
	}
	while(!ques.empty() && begin(ques)->first == 0) {
		auto u = begin(ques)->second;
		auto v = prev(end(ques))->second;
		ques.erase(begin(ques));
		ques.erase(prev(end(ques)));
		if(que[v].back() == u) {
			swap(que[v][que[v].size() - 1], que[v][que[v].size() - 2]);
		}
		b[que[v].back()] = u + 1;
		que[v].pop_back();
		ques.insert({que[v].size(), v});
	}
	int ans = ques.size();
	cout << ans << "\n";
	for(auto it: ques) {
		b[que[it.second][0]] = it.second + 1;
	}
	for(int i = 0; i < n; i++) {
		cout << b[i] << " \n"[i + 1 == n];
	}
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