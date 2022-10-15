/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("H.dat", "r", stdin); freopen("H.sol", "w", stdout);
	int n;
	cin >> n;
	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];

	sort(ar, ar + n);
	while(ar[0] != ar[n - 1]){
		for(int i = n - 1; i > 0; i--)
			if(ar[i] > ar[i - 1]){
				ar[i] -= ar[i - 1];
				break;
			}
		sort(ar, ar + n);
	}
	cout << ar[0] * n;
}