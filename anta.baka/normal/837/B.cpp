#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[100][100];

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	if(n % 3 == 0) {
		int x = 0, y = n / 3, z = 2 * (n / 3);
		if(!(a[x][0] == a[y][0] || a[x][0] == a[z][0] || a[y][0] == a[z][0])) {
			bool ok = true;
			for(int i = 0; i < y; i++)
				for(int j = 0; j < m; j++)
					ok &= (a[i][j] == a[x][0]);
			for(int i = y; i < z; i++)
				for(int j = 0; j < m; j++)
					ok &= (a[i][j] == a[y][0]);
			for(int i = z; i < n; i++)
				for(int j = 0; j < m; j++)
					ok &= (a[i][j] == a[z][0]);
			if(ok) {
				cout << "YES";
				return 0;
			}
		}
	}
	if(m % 3 == 0) {
		int x = 0, y = m / 3, z = 2 * (m / 3);
		if(!(a[0][x] == a[0][y] || a[0][x] == a[0][z] || a[0][y] == a[0][z])) {
			bool ok = true;
			for(int i = 0; i < n; i++)
				for(int j = 0; j < y; j++)
					ok &= (a[i][j] == a[0][x]);
			for(int i = 0; i < n; i++)
				for(int j = y; j < z; j++)
					ok &= (a[i][j] == a[0][y]);
			for(int i = 0; i < n; i++)
				for(int j = z; j < m; j++)
					ok &= (a[i][j] == a[0][z]);
			if(ok) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}