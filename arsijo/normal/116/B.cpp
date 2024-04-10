/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;
	char ar[n][m];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> ar[i][j];
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(ar[i][j] != 'W')
				continue;
			ans++;
			if (i != 0 && ar[i-1][j] == 'P')
				continue;
			if (j != 0 && ar[i][j-1] == 'P')
				continue;
			if (i != n - 1 && ar[i+1][j] == 'P')
				continue;
			if (j != m - 1 && ar[i][j+1] == 'P')
				continue;
			ans--;
		}
	}

	cout << ans;

}