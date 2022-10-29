#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

typedef class Node {
	public:
		int p;
		double E;

		Node(int p, double E) : p(p), E(E) {	}

		boolean operator < (Node b) const {
			return (E != b.E) ? (E > b.E) : (p < b.p);
		}
} Node;

const int N = 1e3 + 5;

const double dinf = 1e100;

int n;
boolean vis[N];
double G[N][N];
double f[N], g[N], P[N];
void dijkstra() {
	for (int i = 1; i <= n; i++) {
		f[i] = dinf, g[i] = 0, P[i] = 1;
	}
	f[n] = g[n] = P[n] = 0;
	while (true) {
		int p = 0;
		double E = dinf;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && f[i] < E) {
				p = i;
				E = f[i];
			}
		}
		vis[p] = true;
		for (int i = 1; i <= n; i++) {
			if ((i ^ p) && f[i] > f[p] && G[i][p] > 0) {
				g[i] += P[i] * G[i][p] * E;
				P[i] *= (1 - G[i][p]);
				f[i] = (g[i] + 1) / (1 - P[i]);
			}
		}
		if (p == 1) {
			break;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1, x; j <= n; j++) {
			scanf("%d", &x);
			G[i][j] = x * 1.0 / 100;
		}
	}
	dijkstra();
	printf("%.9lf", f[1]);
	return 0;
}