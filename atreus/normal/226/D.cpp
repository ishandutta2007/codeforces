/**
 *    author:  Atreus
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

int n, m;

const int maxn = 100 + 10;
int col[maxn], row[maxn], a[maxn][maxn];
bool b[maxn], c[maxn];

void rev_row();

void rev_col(){
	bool found = 0;
	for (int i = 1; i <= m; i++){
		if (col[i] < 0){
			found = 1;
			c[i] ^= 1;
			col[i] *= -1;
			for (int j = 1; j <= n; j++){
				row[j] -= 2 * a[j][i];
				a[j][i] *= -1;
			}
		}
	}
	if (found == 0)
		return;
	rev_row();

}

void rev_row(){
	bool found = 0;
	for (int i = 1; i <= n; i++){
		if (row[i] < 0){
			found = 1;
			b[i] ^= 1;
			row[i] *= -1;
			for (int j = 1; j <= m; j++){
				col[j] -= 2 * a[i][j];
				a[i][j] *= -1;
			}
		}
	}
	if (found == 0)
		return;
	rev_col();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> a[i][j];
			row[i] += a[i][j];
			col[j] += a[i][j];
		}
	}
	rev_row();
	rev_col();
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		cnt += b[i];
	cout << cnt << " ";
	for (int i = 1; i <= n; i++)
		if (b[i])
			cout << i << " ";
	cout << endl;
	cnt = 0;
	for (int i = 1; i <= m; i++)
		cnt += c[i];
	cout << cnt << " ";
	for (int i = 1; i <= m; i++)
		if (c[i])
			cout << i << " ";
}