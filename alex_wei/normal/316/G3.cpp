#include <bits/stdc++.h>
using namespace std;

bool Mbe;
const int N = 1.2e6 + 5;
const int L = 5e4 + 5;
const int S = 26;

string s, t;
long long ans;
int n, l[11], r[11], node, tr[N >> 1][S];
unsigned short val[N][11];
void insert(string s, int id) {
	int p = 0;
	for(char it : s) {
		if(!tr[p][it - 'a']) tr[p][it - 'a'] = ++node;
		p = tr[p][it - 'a'], val[p][id]++;
	}
}

int cnt = 1;
unsigned short ed[N][11], len[N];
int son[N][S], p[N], fa[N], buc[L], id[N];
int ins(int p, int it, unsigned short *ap) {
	int cur = ++cnt; len[cur] = len[p] + 1;
	for(int i = 0; i <= n; i++) ed[cur][i] = ap[i];
	while(!son[p][it]) son[p][it] = cur, p = fa[p];
	if(!p) return fa[cur] = 1, cur;
	int q = son[p][it];
	if(len[p] + 1 == len[q]) return fa[cur] = q, cur;
	int cl = ++cnt; memcpy(son[cl], son[q], S << 2);
	len[cl] = len[p] + 1, fa[cl] = fa[q], fa[q] = fa[cur] = cl;
	while(son[p][it] == q) son[p][it] = cl, p = fa[p];
	return cur;
}
void build() {
	queue <int> q; p[0] = 1, q.push(0);
	while(!q.empty()) {
		int t = q.front(); q.pop();
		for(int i = 0, s; i < S; i++)
			if(s = tr[t][i])
				p[s] = ins(p[t], i, val[s]), q.push(s);
	}
	for(int i = 1; i <= cnt; i++) buc[len[i]]++;
	for(int i = 1; i < L; i++) buc[i] += buc[i - 1];
	for(int i = cnt; i; i--) id[buc[len[i]]--] = i;
	for(int i = cnt; i; i--) {
		for(int j = 0; j <= n; j++) ed[fa[id[i]]][j] += ed[id[i]][j];
		bool ok = 1;
		for(int j = 1; j <= n; j++) ok &= ed[id[i]][j] >= l[j] && ed[id[i]][j] <= r[j];
		if(ok && ed[id[i]][0]) ans += len[id[i]] - len[fa[id[i]]];
	}
}

bool Med;
int main() {
	fprintf(stderr, "%.4lf\n", (&Mbe - &Med) / 1048576.0);
	cin >> s >> n, insert(s, 0);
	for(int i = 1; i <= n; i++) cin >> t >> l[i] >> r[i], insert(t, i);
	build(), cout << ans << endl;
	return 0;
}