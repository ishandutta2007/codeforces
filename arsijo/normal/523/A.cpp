/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
//#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double

int main() {

	int n, m;
	cin >> m >> n;

	char ar[m][n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ar[j][i];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << ar[i][j] << ar[i][j];
		cout << endl;
		for (int j = 0; j < n; j++)
			cout << ar[i][j] << ar[i][j];
		cout << endl;
	}

}