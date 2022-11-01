# include <bits/stdc++.h>
 
using namespace std;
 
const int xn = 1e2+10;
int a[xn][xn];
int b[xn][xn];
 
int main(){
	int n, m;
	cin >> n >> m;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++) cin >> a[i][j];
	}
	vector <int> x, y;
	int ans = 0;
	bool f;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j] == 1){
				/*
				if ((j == n-1 and a[i][j-1] == 0 )or (i == n-1 and a[i-1][j] == 0)){
					cout << -1;
					return 0;
				}
				*/
				if ((b[i][j] == 0 or b[i+1][j] == 0 or b[i][j+1] == 0 or b[i+1][j+1] == 0) and i < n-1 and j < m-1 and a[i][j+1] == 1 and a[i+1][j] == 1 and a[i+1][j+1] == 1){
					b[i][j] = 1, b[i+1][j] = 1, b[i][j+1] = 1, b[i+1][j+1] = 1;
					ans += 1;
					x.push_back(i+1), y.push_back(j+1);
				}
			}
		}
	}
	/*
	for (int i=0; i<n; i++){
		if (i != n-1 and b[i][m-1] == 0 and a[i][m-1] == 1){
			ans += 1;
			x.push_back(i+1), y.push_back(m);
			b[i+1][m-1] = 1;
		}
	}
	for (int j=0; j<m; j++){
		if (j != m-1 and b[n-1][j] == 0 and a[n-1][j] == 1){
			ans += 1;
			x.push_back(n), y.push_back(j+1);
			b[n-1][j+1] = 1;
		}
	}
	*/
	//if (b[n-1][m-1] == 0){
		//cout << -1;
		//return 0;
	//}
	f = 1;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j] != b[i][j]){
				cout << -1;
				return 0;
			}
		}
	}
	cout << ans;
	cout << endl;
	for (int i=0; i<x.size(); i++){
		cout << x[i] << ' ' << y[i] << endl;
	}
}