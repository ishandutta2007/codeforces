#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 2e5 + 10;
 
bitset <N> vis;
set <int> g[N], h[N];
vector <int> res;
int n, m, curr;
int comp[N], value[N], r[N];
vector <int> sw[N];
stack <int> l;
 
void dfsUp (int u) {
    vis[u] = 1;
    for (int v : g[u]) {
        if (!vis[v]) dfsUp(v);
   	}
    l.push(u);
}
 
void dfsDown (int u) {
    comp[u] = curr;
    for (int v : h[u]) {
        if (comp[v] == -1) dfsDown(v);
    }
}
 
int main (int argc, char const *argv[]) {
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= m; ++i) {
    	scanf("%d", r + i);
    }
    for (int i = 1; i <= n; ++i) {
    	int tot; scanf("%d", &tot);
    	while (tot--) {
    		int z; scanf("%d", &z);
    		sw[z].push_back(i);
    	}
    }
    n = n + n;
    for (int i = 1; i <= m; ++i) {
		int a = sw[i][0], b = sw[i][1];
		// cout << a << " " << b << endl;
		a = a + a - 2, b = b + b - 2;
    	if (r[i]) {
    		g[a].insert(b);
    		g[b].insert(a);
    		g[a ^ 1].insert(b ^ 1);
    		g[b ^ 1].insert(a ^ 1);
    	} else {
    		g[a ^ 1].insert(b);
    		g[b].insert(a ^ 1);
    		g[b ^ 1].insert(a);
    		g[a].insert(b ^ 1);
    	}
    }
    // for (int i = 0; i < n; ++i) {
    // 	cout << i << ":";
    // 	for (int xx : g[i]) cout << xx << " ";
    // 		cout << endl;
    // }
    for (int i = 0; i < n; ++i) {
    	h[i] = g[i];
    }
    // while () {
    //     int u, v;
    //     scanf("%d %d", &u, &v);
    //     u = u + u, v = v + v;
    //     if (u < 0) u = -u + 1;
    //     if (v < 0) v = -v + 1;
    //     u -= 2, v -= 2;
    //     g[u ^ 1].push_back(v);
    //     g[v ^ 1].push_back(u);
    //     h[v].push_back(u ^ 1);
    //     h[u].push_back(v ^ 1);
    // }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfsUp(i);
    }
    memset(comp, -1, sizeof comp);
    curr = 0;
    while (!l.empty()) {
        int u = l.top();
        l.pop();
        if (comp[u] == -1) ++curr, dfsDown(u);
    }
    bool flag = 0;
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1]) {
            flag = 1; break;
        }
    }
    puts(flag ? "NO" : "YES");
    return 0;
}