# include <bits/stdc++.h>

using namespace std;

const int xn = 2e2+10;
int a[xn][xn];
int b[xn];

int main(){
	int n;
	cin >> n;
	int m;
	for (int i=0; i<n; i++){
		cin >> m;
		for (int j=0; j<m; j++)
			cin >> a[i][j];
		a[i][m] = a[i][0];
		b[i] = m;
	}
	int t;
	for (int i=0; i<n; i++){
		t = 0;
		for (int j=1; j<=b[i]; j++){
			if (a[i][j]-a[i][j-1] != 1 and a[i][j]-a[i][j-1] != -1){
				t += 1;
			}
		}
		if (t > 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}