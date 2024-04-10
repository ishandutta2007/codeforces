#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, K = N * 30;
int n, R, node, ls[K], rs[K];
vector <int> buc[K];
long long ans;
void modify(int dep, int &x, int v) {
	if(!x) x = ++node;
	buc[x].push_back(v);
	if(dep) modify(dep - 1, v >> dep - 1 & 1 ? rs[x] : ls[x], v);
}
int query(int dep, int x, int v) {
	if(!dep) return 0;
	int b = v >> dep - 1 & 1;
	if(b) return rs[x] ? query(dep - 1, rs[x], v) : (1 << dep - 1) + query(dep - 1, ls[x], v);
	return ls[x] ? query(dep - 1, ls[x], v) : (1 << dep - 1) + query(dep - 1, rs[x], v);
}
void solve(int dep, int x) {
	if(!x) return;
	solve(dep - 1, ls[x]), solve(dep - 1, rs[x]);
	if(!ls[x] || !rs[x]) return;
	int w = 1 << 30;
	if(buc[ls[x]].size() < buc[rs[x]].size()) for(int it : buc[ls[x]]) w = min(w, query(dep - 1, rs[x], it));
	else for(int it : buc[rs[x]]) w = min(w, query(dep - 1, ls[x], it));
	ans += w + (1 << dep - 1);
}
int main() {
	// freopen("1.in", "r", stdin);
	cin >> n;
	for(int i = 1, a; i <= n; i++) scanf("%d", &a), modify(30, R, a);
	solve(30, R);
	cout << ans << endl;
	return 0;
}