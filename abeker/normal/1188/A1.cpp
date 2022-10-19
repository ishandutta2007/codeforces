#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N;
int deg[MAXN];

int main() {
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u]++;
		deg[v]++;
	}
	
	for (int i = 1; i <= N; i++)
		if (deg[i] == 2) {
			puts("NO");
			return 0;
		}
	
	puts("YES");
	
	return 0;
}