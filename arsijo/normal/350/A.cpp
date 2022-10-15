/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

string st = "ROYGBIV";

int main() {
	//freopen("H.dat", "r", stdin); freopen("H.sol", "w", stdout);
	int n, m;
	cin >> n >> m;
	int ar[n], ar2[m];
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	for(int i = 0; i < m; i++)
		cin >> ar2[i];
	sort(ar, ar + n);
	sort(ar2, ar2 + m);
	int a = max(ar[n - 1], ar[0] * 2);
	if(ar2[0] <= a)
		cout << -1;
	else
		cout << a;
}