#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

int n, m;
vector<int> G[N], rG[N];

int deg[N], cnt[N];
int ord[N], idx[N];
int pre[N], pre2[N], suf[N], suf2[N];
vector<int> E[N];

void topusort() {
	queue<int> Q;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!deg[i]) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int p = Q.front();
		Q.pop();
		ord[++cnt] = p;
		idx[p] = cnt;
		for (auto e : G[p]) {
			if (!--deg[e]) {
				Q.push(e);
			}
		}
	}
}

int only[N];

void solve_suf() {
	int mx = 0, id = 0, scmx = 0;
	for (int i = 1; i <= n + 1; i++) {
		only[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int p = ord[suf[i]];
		only[p]++;
		E[suf2[i]].push_back(p);
	}
	for (int i = 1; i <= n; i++) {
		int p = ord[i];
		for (auto e : E[i])
			only[e]--;
		E[i].clear();
		if (scmx > i) {
			cnt[p] = 2;
//			cerr << "suf2 " << p << '\n';
		} else if (mx > i) {
			cnt[p] = 1 + !!only[id];
//			cerr << "suf " << p << '\n';
		}
		if (suf[p] > mx) {
			swap(mx, scmx);
			mx = suf[p];
			id = p;
		} else if (suf[p] > scmx) {
			scmx = suf[p];
		}
	}
}
void solve_pre() {
	int mi = n + 1, id = 0, scmi = n + 1;
	for (int i = 1; i <= n; i++) {
		only[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int p = ord[pre[i]];
		only[p]++;
		E[pre2[i]].push_back(p);
	}
	for (int i = n; i; i--) {
		int p = ord[i];
		for (auto e : E[i])
			only[e]--;
		E[i].clear();
		if (scmi < i) {
			cnt[p] = 2;
//			cerr << "pre2 " << p << '\n';
		} else if (mi < i) {
			cnt[p] += 1 + !!only[id];
//			cerr << "pre " << p << '\n';
		}
		if (pre[p] < mi) {
			swap(mi, scmi);
			mi = pre[p];
			id = p;
		} else if (pre[p] < scmi) {
			scmi = pre[p];
		}
//		cerr << "qaq: " << i << " " << mi << " " << scmi << '\n';
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		rG[v].push_back(u);
		++deg[v];
	}
	topusort();
	for (int i = 1; i <= n; i++) {
		pre[i] = pre2[i] = 0;
		for (auto e : rG[i]) {
			if (idx[e] > pre[i]) {
				swap(pre[i], pre2[i]);
				pre[i] = idx[e];
			} else if (idx[e] > pre2[i]) {
				pre2[i] = idx[e];
			}
		}
		suf[i] = suf2[i] = n + 1;
		for (auto e : G[i]) {
			if (idx[e] < suf[i]) {
				swap(suf[i], suf2[i]);
				suf[i] = idx[e];
			} else if (idx[e] < suf2[i]) {
				suf2[i] = idx[e];	
			}
		}
	}
/*	for (int i = 1; i <= n; i++)
		cerr << idx[i] << " ";
	cerr << '\n';
	for (int i = 1; i <= n; i++)
		cerr << pre[i] << " ";
	cerr << '\n';
	for (int i = 1; i <= n; i++)
		cerr << suf[i] << " ";
	cerr << '\n'; */
	
	solve_suf();
	solve_pre();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (cnt[i] < 2);
//		if (cnt[i] < 2) {
//			cerr << i << '\n';
//		}
	}
	printf("%d\n", ans);
	return 0;
}