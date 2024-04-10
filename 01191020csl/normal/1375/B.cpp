#include<bits/stdc++.h>
using namespace std;
int a[301][301];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) 
				cin >> a[i][j];
		bool res = 1;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				int tmp = 4;
				if (i == 1) --tmp;
				if (j == 1) --tmp;
				if (i == n) --tmp;
				if (j == m) --tmp;
				if (tmp < a[i][j]) res = 0;
				a[i][j] = tmp;
			}
		if (!res) {
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cout << a[i][j] << ' ';
			cout << endl;
		}
	}
}