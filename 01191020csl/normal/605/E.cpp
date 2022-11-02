#include<bits/stdc++.h>
using namespace std;
int p[1001][1001];
int vis[1001];
double dis[1001], tmp[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> p[i][j];
	for (int i = 1; i <= n; i++) dis[i] = 1e18;
	dis[n] = 0;
	for (int i = 1; i <= n; i++) {
		int u = 0;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && (!u || dis[j] < dis[u])) u = j;
		vis[u] = 1;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && p[j][u]) {
				if (dis[j] > 10000) dis[j] = 0;
				else dis[j] -= 1.0/tmp[j];
				double lt = tmp[j];
				tmp[j] = 1-(1-tmp[j])*(1-p[j][u]/100.0);
				if (lt > 0) dis[j] *= lt/tmp[j];
				dis[j] += (1-lt)*p[j][u]/100.0/tmp[j]*dis[u] + 1.0/tmp[j];
			}
	}
	cout << fixed << setprecision(15) << dis[1] << endl;
}