# include <bits/stdc++.h>

using namespace std;

const int xn = 1e2+10;

bool a[xn][xn];
int b[xn][xn], c[xn][xn];

int main(){
	int n, m, t;
	bool fl1;
	cin >> n >> m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++) cin >> a[i][j], b[i][j] = -1, c[i][j] = a[i][j];
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j] == 0){
				for (int k=0; k<m; k++) b[i][k] = 0;
				for (int k=0; k<n; k++) b[k][j] = 0;
			}
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (c[i][j] and b[i][j] == -1){
				b[i][j] = 1;
				for (int k=0; k<m; k++) c[i][k] = 0;
				for (int k=0; k<n; k++) c[k][j] = 0;
			}
		}
	}
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (a[i][j]){
				fl1 = 0;
				for (int k=0; k<m; k++) if (b[i][k]) fl1 = 1;
				for (int k=0; k<n; k++) if (b[k][j]) fl1 = 1;
				if (fl1 == 0){
					cout << "NO";
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (b[i][j]) cout << 1 << ' ';
			else cout << b[i][j] << ' ';
		}
		cout << endl;
	}
}