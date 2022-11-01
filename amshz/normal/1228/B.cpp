# include <bits/stdc++.h>

using namespace std;

const int xn = 1e3+10;
const int md = 1e9+7;
int a[xn][xn];
int c[xn], r[xn]; 

int main(){
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++) cin >> r[i];
	for (int i=0; i<m; i++) cin >> c[i];
	for (int i=0; i<n; i++){
		for (int j=0; j<r[i]; j++) a[i][j] = 1;
		a[i][r[i]] = -1;
	}
	for (int i=0; i<m; i++){
		for (int j=0; j<c[i]; j++){
			if (a[j][i] == 0) a[j][i] = 1;
			else if (a[j][i] == -1){
				cout << 0;
				return 0;
			}
		}
		if (a[c[i]][i] == 0) a[c[i]][i] = -1;
		else if (a[c[i]][i] == 1){
			cout << 0;
			return 0;
		}
	}
	int t = 0;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j] == 0) t++;
		}
	}
	long long ans = 1;
	for (int i=0; i<t; i++){
		ans *= 2;
		ans = ans%md;
	}
	cout << ans;
}