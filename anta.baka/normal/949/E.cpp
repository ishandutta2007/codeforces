#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,sse4,tune=native")
#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
const int maxn = 1e5, INF = 1e9;
 
vector<int> cur, opt;
 
void solve(int lvl, vector<int> &v) {
	if(lvl > 20) return;
	if(sz(v) == 1 && v[0] == 0) {
		if(opt.empty() || sz(cur) < sz(opt)) opt = cur;
		return;
	}
	bool any = false;
	for(int x : v) if(x & 1) any = true;
	if(!any) {
		for(int i = 0; i < sz(v); i++) v[i] /= 2;
		v.erase(unique(all(v)), v.end());
		solve(lvl + 1, v);
		return;
	}
	vector<int> v1 = v;
	for(int i = 0; i < sz(v1); i++) {
		if(v1[i] & 1) v1[i]++;
		v1[i] /= 2;
	}
	v1.erase(unique(all(v1)), v1.end());
	cur.push_back(-lvl);
	solve(lvl + 1, v1);
	cur.pop_back();
	vector<int> v2 = v;
	for(int i = 0; i < sz(v2); i++) {
		if(v2[i] & 1) v2[i]--;
		v2[i] /= 2;
	}
	v2.erase(unique(all(v2)), v2.end());
	cur.push_back(lvl);
	solve(lvl + 1, v2);
	cur.pop_back();
}
 
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(all(a)); a.erase(unique(all(a)), a.end());
	if(a[0] == 0 && sz(a) == 1) return cout << 0, 0;
	solve(1, a);
	int k = opt.back(); if(k < 0) k = -k;
	cout << sz(opt) << '\n';
	for(int x : opt) if(x < 0) cout << -(1 << (-x - 1)) << ' ';
	else cout << (1 << (x - 1)) << ' ';
}