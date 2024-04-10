/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define mod % 1000000007
const int MAX = 500;

int X[4] = { -1, 0, 1, 0 }, Y[4] = { 0, 1, 0, -1 };
bool bol[MAX][MAX];
char ar[MAX][MAX];
int need, n, m;

void dfs(int x1, int y1){
	if(need <= 0)
		return;
	bol[x1][y1] = true;
	need--;
	for(int i = 0; i < 4; i++){
		int x2 = x1 + X[i], y2 = y1 + Y[i];
		if(x2 < 0 || y2 < 0 || x2 >= n || y2 >= m || bol[x2][y2] || ar[x2][y2] != '.')
			continue;
		dfs(x2, y2);
	}
}

int main() {

	int s;
	cin >> n >> m >> s;
	int x1 = -1, y1 = -1, t = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> ar[i][j];
			if(ar[i][j] == '.'){
				x1 = i;
				y1 = j;
				t++;
			}
		}
	ms(bol);
	need = t - s;
	dfs(x1, y1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cout << (bol[i][j] || ar[i][j] != '.' ? ar[i][j] : 'X');
		cout << endl;
	}

}