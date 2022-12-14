#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
typedef complex<ld> point;
const int maxn = 300 + 5;

int a[maxn][maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t --){
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		if (max({a[0][0], a[n-1][0], a[0][m-1], a[n-1][m-1]}) > 2){
			cout << "NO\n";
			continue;
		}
		bool found = false;
		for (int i = 0; i < n; i++)
			if (max(a[i][0], a[i][m-1]) > 3)
				found = true;
		for (int j = 0; j < m; j++)
			if (max(a[0][j], a[n-1][j]) > 3)
				found = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] > 4)
					found = true;
		if (found){
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				cout << 4 - (i == 0 or i == n-1) - (j == 0 or j == m-1) << " ";
			}
			cout << '\n';
		}
	}
}