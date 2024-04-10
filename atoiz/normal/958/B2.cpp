#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

const int MAX = 100007;

int n, root = 0, bestlen = 0, leaf1, leaf2, bestroot;
vector<int> conn[MAX + 1];
int favleaf[MAX + 1], favchild[MAX + 1], favlen[MAX + 1], par[MAX + 1];
bool dead[MAX + 1];
priority_queue< pair<int, int> > pq;

void dfs(int u)
{
	favchild[u] = -1; favlen[u] = 1; favleaf[u] = u;
    for (int v : conn[u]) {
        if (par[u] == v) continue;
        par[v] = u;
        dfs(v);
        if (favlen[u] < favlen[v] + 1) {
            favchild[u] = v;
            favleaf[u] = favleaf[v];
            favlen[u] = favlen[v] + 1;
        }
    }
}

void dfslen(int u)
{
	int curchild1, curchild2, startIdx = 3;
    if (conn[u].size() == 1) {
        if (favlen[u] > bestlen) {
			bestlen = favlen[u];
			bestroot = u;
			leaf1 = leaf2 = favleaf[u];
        }
		for (int v : conn[u]) if (v != par[u]) dfslen(v);
		return;
    }
    if (u != root && conn[u].size() == 2) {
        if (favlen[u] > bestlen) {
			bestlen = favlen[u];
			bestroot = u;
			leaf1 = leaf2 = favleaf[u];
        }
		for (int v : conn[u]) if (v != par[u]) dfslen(v);
		return;
    }
    if (conn[u][0] == par[u]) { curchild1 = conn[u][1]; curchild2 = conn[u][2]; }
    else if (conn[u][1] == par[u]) { curchild1 = conn[u][0]; curchild2 = conn[u][2]; }
    else  { curchild1 = conn[u][0]; curchild2 = conn[u][1]; startIdx = 2; }

    if (favlen[curchild1] > favlen[curchild2]) swap(curchild1, curchild2);
    for (int i = startIdx; i < conn[u].size(); ++i) {
		int v = conn[u][i];
		if (v == par[u]) continue;
        if (favlen[curchild1] < favlen[v]) {
			curchild1 = v;
			if (favlen[curchild1] > favlen[curchild2]) swap(curchild1, curchild2);
        }
    }

    if (favlen[curchild1] + favlen[curchild2] + 1 > bestlen) {
//		cerr << u << ": " << curchild1 << ' ' << curchild2 << endl;
        bestlen = favlen[curchild1] + favlen[curchild2] + 1;
        leaf1 = favleaf[curchild1];
        leaf2 = favleaf[curchild2];
        bestroot = u;
    }


    for (int v : conn[u]) {
		if (v != par[u]) dfslen(v);
    }
}

void kill(int u, int r)
{
    if (dead[u]) return;
//    cerr << "killed " << u << endl;
    dead[u] = 1;
    for (int v : conn[u]) {
        if (dead[v] || v == par[u]) continue;
        pq.push({ favlen[v], v });
//        cerr << "pq " << favlen[v] << ' ' << v << ": " << u << endl;
//		cerr << "add " << v << endl;
    }
    if (par[u] != r) kill(par[u], r);
}

int main()
{
	for (int i = 0; i <= MAX; ++i) {
		conn[i].resize(0);
		favleaf[i] = -1;
		favchild[i] = -1;
		favlen[i] = -1;
		par[i] = -1;
		dead[i] = 0;
	}

	cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		conn[u].push_back(v);
		conn[v].push_back(u);
	}

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
		cout << "1 2" << endl;
		return 0;
    }

    root = 1;
	dfs(root);
	dfslen(root);
//	cerr << leaf1 << ' ' << leaf2 << ' ' << bestroot << endl;
//	for (int i = 1; i <= n; ++i) cerr << par[i] << ' '; cerr << endl;
	root = bestroot;
	par[root] = -1;
	dfs(root);
	kill(leaf1, bestroot); kill(leaf2, bestroot); kill(bestroot, par[bestroot]);
//	for (int i = 1; i <= n; ++i) cerr << par[i] << ' '; cerr << endl;
    cout << 1 << ' ' << bestlen << ' ';

//    for (int v : conn[root]) {
//        if (dead[v]) continue;
//        pq.push({ favlen[v], v });
//    }

    int curcnt = bestlen;
    for (int k = 3; k <= n; ++k) {
        if (pq.empty()) {
            if (curcnt != n) return 911;
            cout << curcnt << ' ';
            continue;
        }
        pair<int, int> p = pq.top(); pq.pop();
        curcnt += p.first;
        kill(favleaf[p.second], root);
        cout << curcnt << ' ';
    }
    cout << endl;
    }