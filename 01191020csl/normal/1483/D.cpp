#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();
	while (c != '-' && !isdigit(c)) c = getchar();
	int neg = 0;
	if (c == '-') neg = 1, c = getchar();
	int num = 0;
	while (isdigit(c)) {
		num = num * 10 + c - '0';
		c = getchar();
	}
	return neg ? -num : num;
}
long long dis[601][601], tmp[601][601];
int u[180001], v[180001], w[180001];
int main() {
	int n = read(), m = read();
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= m; i++) {
		u[i] = read(), v[i] = read(), w[i] = read();
		dis[u[i]][v[i]] = dis[v[i]][u[i]] = w[i];
	}
	for (int i = 1; i <= n; i++) dis[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	int q = read();
	for (int i = 1; i <= q; i++) {
		int u = read(), v = read(), l = read();
		for (int j = 1; j <= n; j++) tmp[u][j] = max(tmp[u][j], l - dis[v][j]);
	}
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		bool flag = 0;
		for (int j = 1; !flag && j <= n; j++)
			if (dis[j][u[i]] + w[i] <= tmp[j][v[i]] ||
				dis[j][v[i]] + w[i] <= tmp[j][u[i]]) flag = 1;
		if (flag) ++cnt;
	}
	cout << cnt << endl;
}