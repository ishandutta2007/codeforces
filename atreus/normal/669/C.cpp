#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100 + 10;

int a[maxn][maxn], b[maxn * maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = i * m + j;
	while (q --){
		int t;
		cin >> t;
		if (t == 1){
			int r;
			cin >> r;
			r --;
			int tmp = a[r][0];
			for (int i = 1; i < m; i++)
				a[r][i - 1] = a[r][i];
			a[r][m - 1] = tmp;
		}
		else if (t == 2){
			int c;
			cin >> c;
			c --;
			int tmp = a[0][c];
			for (int i = 1; i < n; i++)
				a[i - 1][c] = a[i][c];
			a[n - 1][c] = tmp;
		}
		else{
			int r, c, x;
			cin >> r >> c >> x;
			r --, c --;
			b[a[r][c]] = x;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cout << b[i * m + j] << " \n"[j == m-1];
}