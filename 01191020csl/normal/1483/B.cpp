#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}
int a[100001], nxt[100001], vis[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, p = 1;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i], nxt[i] = i + 1, vis[i] = 0;
		nxt[n] = 1;
		int last = 1;
		queue<int> q;
		vector<int> ans;
		do {
			p = nxt[p];
			if (last && gcd(a[last], a[p]) == 1) {
				nxt[last] = nxt[p], vis[p] = 1, ans.push_back(p);
				if (gcd(a[last], a[nxt[p]]) == 1) q.push(last);
				last = 0;
			}
			else last = p;
		} while (p != 1);
		while (q.size()) {
			int u = q.front();
			q.pop();
			if (vis[u]) continue;
			ans.push_back(nxt[u]), vis[nxt[u]] = 1;
			if (!vis[u]) {
				nxt[u] = nxt[nxt[u]];
				if (gcd(a[u], a[nxt[u]]) == 1) q.push(u);
			}
		}
		cout << ans.size();
		for (int i : ans) cout << ' ' << i;
		cout << endl;
	}
}