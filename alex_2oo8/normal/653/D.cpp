#include<bits/stdc++.h>

#define next olo
#define prev ololo

using namespace std;

int a[500], b[500], c[500], next[55], prev[55], h[55], n;
long long q[55][55], p[55], f[55][55];

void increaseFlowOnEdge(int u, int v, int d) {
	q[u][v] -= d;
	q[v][u] += d;
	p[u] -= d;
	p[v] += d;
	
	f[u][v] += d;
}

void setNext(int u, int v) {
	next[u] = v;
	prev[v] = u;
}

void lift(int v) {
	h[v] = 1000000000;
	for (int i = 1; i <= n; i++)
		if (q[v][i] > 0)
			h[v] = min(h[v], h[i] + 1);
	
	setNext(prev[v], next[v]);
	setNext(v, next[0]);
	setNext(0, v);
}

void push(int v) {
	for (int i = 1; i <= n && p[v] > 0; i++)
		if (h[v] == h[i] + 1)
			increaseFlowOnEdge(v, i, min(p[v], q[v][i]));
}

long long maxflow(int source, int target) {
	for (int i = 0; i <= n; i++) {
		h[i] = p[i] = 0;
		for (int j = 0; j <= n; j++) f[i][j] = 0;
	}
	
	h[source] = n;
	for (int i = 1; i <= n; i++) increaseFlowOnEdge(source, i, q[source][i]);
	for (int i = 0; i <= n; i++) setNext(i, i + 1);
	
	setNext(n, 0);
	setNext(prev[source], next[source]);
	setNext(prev[target], next[target]);
	
	int v = 0;
	bool ok = false;
	while ((v == 0 && ok) == false) {
		ok = (ok || v == 0) && p[v] == 0;
		
		while (p[v] > 0) {
			push(v);
			
			if (p[v] > 0) lift(v);
		}
		
		v = next[v];
	}
	
	long long flow = 0;
	for (int i = 1; i <= n; i++) flow += f[source][i] - f[i][source];
	
	return flow;
}

int main() {
	int m, x;
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < m; i++) scanf("%d %d %d", a + i, b + i, c + i);
	
	long double l = 0, r = 1234567;
	for (int i = 0; i < 100; i++) {
		long double v = (l + r) / 2;
		
		for (int x = 0; x <= n; x++)
			for (int y = 0; y <= n; y++)
				q[x][y] = 0;
		
		for (int x = 0; x < m; x++) {
			q[a[x]][b[x]] = (long long)(c[x] / v);
		}
		
		if (maxflow(1, n) < x) r = v;
		else l = v;
	}
	
	printf("%.12f\n", (double)(x * l));
	
	return 0;
}