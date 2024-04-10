#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100 + 10 + 10;

int dis[maxn][maxn], x[maxn], y[maxn], a[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, d;
	cin >> n >> d;
	for (int i = 2; i <= n - 1; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = d * (abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[j];
	for (int i = 1; i <= n; i++)
		dis[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	cout << dis[1][n] << '\n';
}