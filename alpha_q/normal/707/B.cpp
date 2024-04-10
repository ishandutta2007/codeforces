#include <bits/stdc++.h>

using namespace std;

struct edge {
	int u, v, w;
	bool operator < (const edge &e) const {
		return w < e.w;
	}
};

const int N = 1e5 + 10;

bool s[N];
int n, m, k;
edge e[N];

int main (int argc, char const *argv[]) {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) 
		scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
	for (int i = 1; i <= k; ++i) {
		int x; scanf("%d", &x);
		s[x] = 1;
	}
	
	sort (e + 1, e + m + 1);
	
	for (int i = 1; i <= m; ++i) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if ((s[u] and !s[v]) or (s[v] and !s[u])) {
			printf("%d\n", w);
			return 0;
		}
	}
	
	printf("-1\n");
	return 0;
}