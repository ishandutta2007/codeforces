# include <bits/stdc++.h>

using namespace std;

const int xn = 1e3+10;
long long int a[xn][xn];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cin >> a[i][j];
		}
	}
	//int r;
	long long int r = int(sqrt(a[0][1]*a[0][2]/a[1][2]));
	//long long r = a[0][1]*a[0][2];
	cout << r << ' ';
	for (int i=1; i<n; i++) cout << a[0][i]/r << ' ';
	return 0;
}