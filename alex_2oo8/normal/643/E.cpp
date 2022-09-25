#include<bits/stdc++.h>

using namespace std;

const int MX = 500000;

int par[MX];
long double p[MX][44];

void add(int v, bool inc, int dep) {
	if (inc && par[v] != -1) {
		for (int i = 1; i < 44 - dep; i++) p[par[v]][i] *= (p[v][i - 1] + 1) / 2;
	}
	
	if (dep > 0 && par[v] != -1) add(par[v], inc, dep - 1);
	
	if (inc == false && par[v] != -1) {
		for (int i = 1; i < 44 - dep; i++) p[par[v]][i] /= (p[v][i - 1] + 1) / 2;
	}
}

int main() {
	par[0] = -1;
	for (int i = 1; i < 44; i++) p[0][i] = 1;
	int q, n = 1;
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int t, v;
		scanf("%d %d", &t, &v);
		v--;
		if (t == 1) {
			par[n++] = v;
			
			add(v, false, 41);
			
			p[n - 1][0] = 0;
			for (int j = 1; j < 44; j++) p[n - 1][j] = 1;
			
			add(n - 1, true, 42);
		}
		else {
			long double ans = 0;
			for (int j = 1; j < 44; j++) ans += 1 - p[v][j];
			
			printf("%.12f\n", (double)(ans));
		}
	}
	
	return 0;
}