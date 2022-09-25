#include<bits/stdc++.h>

#define prev ololo

using namespace std;

const int MX = 300000, INF = 1000000, MAXV = 2000000;

struct {
	int v, d, next;
} E[4 * MAXV];

int b[MX], d[MX], fwt[MX + 1], V, first[MAXV], dist[MAXV], s[2 * MAXV], prev[MAXV], n;
vector<int> v;

void addEdge(int u, int v, int d) {
	static int ee = 0;
	ee++;
	
	E[ee].v = v;
	E[ee].d = d;
	E[ee].next = first[u];
	first[u] = ee;
}

void BFS(int start) {
	for (int i = 0; i < V; i++) dist[i] = INF;
	
	int l = MAXV, r = MAXV + 1;
	s[l] = start;
	dist[start] = 0;
	while (l < r) {
		int v = s[l++];
		for (int i = first[v]; i > 0; i = E[i].next) {
			if (dist[v] + E[i].d < dist[E[i].v]) {
				dist[E[i].v] = dist[v] + E[i].d;
				prev[E[i].v] = v;
				
				if (E[i].d == 0) s[--l] = E[i].v;
				else s[r++] = E[i].v;
			}
		}
		
		first[v] = 0;
	}
}

void dfs(int v) {
	if (v == 0) return;
	
	dfs(prev[v]);
	
	if (v <= n) printf("%d ", v);
}

int find(int x) {
	int k = 0;
	for (int i = (1 << 18); i > 0; i /= 2)
		if (k + i < v.size() && v[k + i] <= x)
			k += i;
	
	return k + 1;
}

void fwt_add(int x, int v) {
	while (x <= MX) {
		addEdge(V, fwt[x], 0);
		addEdge(V, v, 1);
		fwt[x] = V++;
		
		x += x & -x;
	}
}

void fwt_get(int x, int v) {
	while (x) {
		addEdge(v, fwt[x], 0);
		
		x -= x & -x;
	}
}

vector< pair<int, int> > e;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, c;
		scanf("%d %d %d %d", &a, b + i, &c, d + i);
		
		e.push_back(make_pair(a, -(i + 1)));
		e.push_back(make_pair(c, i + 1));
		
		v.push_back(b[i]);
		v.push_back(d[i]);
	}
	
	e.push_back(make_pair(0, 0));
	v.push_back(0);
	
	sort(v.begin(), v.end());
	sort(e.begin(), e.end());
	
	V = n + 1;
	for (auto E : e) {
		if (E.second == 0) fwt_get(find(0)	, 0);
		else if (E.second < 0) fwt_add(find(b[-E.second - 1]), -E.second);
		else fwt_get(find(d[E.second - 1]), E.second);
	}
	
	BFS(0);
	
	if (dist[n] == INF) printf("-1\n");
	else {
		printf("%d\n", dist[n]);
		
		dfs(n);
		
		printf("\n");
	}
	
	return 0;
}