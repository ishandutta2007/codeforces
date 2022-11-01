#include<bits/stdc++.h>
using namespace std;
int head[401], ver[400001], nxt[400001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
}
char typ[30];
int nxtv[30], nxtc[30];
int base[401];
char s[205];
bool check(int n) {
	for (int i = 1; i <= n * 2; i++)
		for (int j = head[i]; j; j = nxt[j]) {
			int p1 = (i-1)%n+1, t1 = (i-1)/n, p2 = (ver[j]-1)%n+1, t2 = (ver[j]-1)/n;
			if (typ[s[p1]-'a'] != (t1?'C':'V') || typ[s[p2]-'a'] == (t2?'C':'V')) continue;
			return 0;
		}
	return 1;
}
int dfn[401], low[401], cnt;
int stk[401], top;
int vis[401], scc[401], num;
void tarjan(int x) {
	dfn[x] = low[x] = ++cnt;
	stk[++top] = x, vis[x] = 1;
	for (int i = head[x]; i; i = nxt[i])
		if (!vis[ver[i]]) tarjan(ver[i]), low[x] = min(low[x], low[ver[i]]);
		else if (vis[ver[i]] == 1) low[x] = min(low[x], dfn[ver[i]]);
	if (dfn[x] == low[x]) {
		++num;
		while (stk[top] != x) {
			vis[stk[top]] = 2;
			scc[stk[top--]] = num;
		}
		vis[stk[top]] = 2;
		scc[stk[top--]] = num;
	}
}
bool _2sat(int n) {
	memset(vis + 1, 0, sizeof(int)*n*2);
	cnt = num = 0;
	for (int i = 1; i <= n * 2; i++) 
		if (!vis[i]) tarjan(i);
	for (int i = 1; i <= n; i++)
		if (scc[i] == scc[i+n]) return 0;
	return 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> typ;
	int l = strlen(typ);
	int visv = 0, visc = 0;
	for (int i = 0; i < l; i++) {
		if (typ[i] == 'V') visv = 1;
		else visc = 1;
		nxtv[i] = nxtc[i] = l;
		for (int j = i; j < l; j++) {
			if (typ[j] == 'V' && nxtv[i] == l) nxtv[i] = j;
			if (typ[j] == 'C' && nxtc[i] == l) nxtc[i] = j;
		}
	}
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int p1, p2;
		char t1, t2;
		cin >> p1 >> t1 >> p2 >> t2;
		t1 = t1 == 'V' ? 0 : 1;
		t2 = t2 == 'V' ? 0 : 1;
		addedge(p1 + t1 * n, p2 + t2 * n);
		addedge(p2 + (1-t2) * n, p1 + (1-t1) * n);
	}
	if (!visv)
		for (int i = 1; i <= n; i++) addedge(i, i + n);
	if (!visc)
		for (int i = 1; i <= n; i++) addedge(i + n, i);
	memcpy(base + 1, head + 1, sizeof(int) * n * 2);
	int sz0 = sz;
	cin >> s + 1;
	if (check(n)) {
		cout << s + 1 << endl;
		return 0;
	}
	int p = n;
	while (1) {
		if (!p) {
			puts("-1");
			return 0;
		}
		int s0 = s[p] - 'a' + 1;
		--p;
		if (s0 == l) continue;
		int t = typ[s0]=='V'?0:1;
		if ((t?nxtc[s0]:nxtv[s0])==l) continue;
		memcpy(head + 1, base + 1, sizeof(int) * n * 2), sz = sz0;
		for (int i = 1; i <= p; i++) {
			int t0 = typ[s[i]-'a']=='V'?0:1;
			addedge(i + (1-t0)*n, i + t0 * n);
		}
		addedge(p + 1 + (1-t)*n, p + 1 + t * n);
		if (_2sat(n)) {
			s[++p] = (t?nxtc[s0]:nxtv[s0]) + 'a';
			break;
		}
		t ^= 1;
		if ((t?nxtc[s0]:nxtv[s0])==l) continue;
		memcpy(head + 1, base + 1, sizeof(int) * n * 2), sz = sz0;
		for (int i = 1; i <= p; i++) {
			int t0 = typ[s[i]-'a']=='V'?0:1;
			addedge(i + (1-t0)*n, i + t0 * n);
		}
		addedge(p + 1 + (1-t)*n, p + 1 + t * n);
		if (_2sat(n)) {
			s[++p] = (t?nxtc[s0]:nxtv[s0]) + 'a';
			break;
		}
	}
	while (p < n) {
		++p;
		int t = typ[0] == 'V' ? 0 : 1;
		memcpy(head + 1, base + 1, sizeof(int) * n * 2), sz = sz0;
		for (int i = 1; i < p; i++) {
			int t0 = typ[s[i]-'a']=='V'?0:1;
			addedge(i + (1-t0)*n, i + t0 * n);
		}
		addedge(p + (1-t)*n, p + t * n);
		if (_2sat(n)) s[p] = 'a';
		else s[p] = (t?nxtv[0]:nxtc[0]) + 'a';
	}
	cout << s + 1 << endl;
}