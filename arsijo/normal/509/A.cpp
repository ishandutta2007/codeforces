/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;
#define input freopen("input.txt", "r", stdin);
#define sync ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int n;
	cin >> n;
	int ar[n][n];
	for(int i = 0; i < n; i++){
		ar[i][0] = 1;
		ar[0][i] = 1;
	}
	for(int i = 1; i < n; i++)
		for(int j = 1; j < n; j++)
			ar[i][j] = ar[i - 1][j] + ar[i][j - 1];
	cout << ar[n - 1][n - 1];
}