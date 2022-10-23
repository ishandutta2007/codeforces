# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 105;
int T, n;
int a[MAXN];
bool f[MAXN][MAXN][2];
int main(){
	ios::sync_with_stdio(false);
	f[0][0][0] = true;
	for (int i = 0; i < MAXN; i++){
		for (int j = 0; j < MAXN; j++){
			if (i == 0 && j == 0) continue;
			for (int k = 0; k < 2; k++){
				if (i >= 1) f[i][j][k] |= !f[i - 1][j][k ^ ((i - 1) & 1)];
				if (j >= 1) f[i][j][k] |= !f[i][j - 1][k ^ 1 ^ (i & 1)];
			}
		}
	}
	cin >> T;
	while (T--){
		cin >> n;
		int cnt = 0;
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			a[i] = a[i] & 1;
			cnt += a[i];
		}
		if (f[cnt][n - cnt][0]) cout << "Alice\n";
		else cout << "Bob\n";
	}
	return 0;
}