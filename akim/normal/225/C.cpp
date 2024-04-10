#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e3;

int n,m, e[2][N], x,y;
char a[N][N];
int d[N][N][2];

main (){
	cin >> n >> m  >> x >> y;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	for (int j = 1; j <= m; j++){
		int sum = 0;
		for (int i = 1; i <= n; i++){
			sum += (a[i][j] == '#');
		}
		e[0][j] = sum;
		e[1][j] = n - sum;
	}
	/*for (int j = 1; j <= m; j++){
		cout << e[0][j] << " " << e[1][j] << endl;
	}*/

	for (int i = 0; i <= m + 2; i++){
		for (int j = 0; j <= y; j++){
			d[i][j][0] = d[i][j][1] = (1 << 30);
		}
	}
	d[1][0][0] = d[1][0][1] = 0;
	for (int i = 1; i <= m + 1; i++){
		for (int j = 0; j <= y; j++){
			d[i + 1][j + 1][0] = min (d[i][j][0] + e[0][i], d[i + 1][j + 1][0]);
			d[i + 1][j + 1][1] = min (d[i][j][1] + e[1][i], d[i + 1][j + 1][1]);
			if (j >= x)d[i + 1][1][0] = min (d[i + 1][1][0], d[i][j][1] + e[0][i]);
			if (j >= x)d[i + 1][1][1] = min (d[i + 1][1][1], d[i][j][0] + e[1][i]);
		}
	}
	int mini = (1 << 30);
	for (int i = x; i <= y; i++){
		mini = min(d[m + 1][i][1], mini);
		mini = min (d[m + 1][i][0], mini);
	}
	cout << mini;
}