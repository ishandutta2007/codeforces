#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int maxn = 500 + 10;
const int mod = 1e9 + 9;
const int base = 11;

int a[maxn][maxn], b[maxn][maxn];
string s[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n, m, q;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = " " + s[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			bool me = 0;
			if (j < m)
				me = (s[i][j] == '.' and s[i][j + 1] == '.');
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + me;
			if (i < n)
				me = (s[i][j] == '.' and s[i + 1][j] == '.');
			b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + me;
		}
	}
	cin >> q;
	while (q --){
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int ver = a[r2][c2-1] - a[r1-1][c2-1] - a[r2][c1-1] + a[r1-1][c1-1];
		int hor = b[r2-1][c2] - b[r1-1][c2] - b[r2-1][c1-1] + b[r1-1][c1-1];
		cout << ver + hor << '\n';
	}
}