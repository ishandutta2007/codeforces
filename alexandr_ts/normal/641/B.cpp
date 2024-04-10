#include <iostream>
#include <stdio.h>
#include <string>
#include <set>

using namespace std;

struct query {
	int type;
	int a, b, c;
} res[10000 + 10];

const int MAXN = 101;
int f[MAXN + 1][MAXN + 1], inf = 0;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = inf;
	for (int i = 0; i < q; i++) {
		cin >> res[i].type;
		if (res[i].type <= 2) {
			cin >> res[i].a;
		}
		else
			cin >> res[i].a >> res[i].b >> res[i].c;
	}
	for (int i = q - 1; i >= 0; i--) {
		int a = res[i].a, b = res[i].b, c = res[i].c;
		if (res[i].type == 3)
			f[a][b] = c;
		else if (res[i].type == 2) {
			int cnt = f[n][a];
			for (int j = n; j >= 2; j--)
				f[j][a] = f[j - 1][a];
			f[1][a] = cnt;
		}
		else {
			int cnt = f[a][m];
			for (int j = m; j >= 2; j--)
				f[a][j] = f[a][j - 1];
			f[a][1] = cnt;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << f[i][j] << " ";
		cout << endl;
	}
	return 0;
}