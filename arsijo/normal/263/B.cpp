/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);
	if (k > n){
		cout << -1;
	}else{
		cout << ar[n - k] << " " << ar[n - k];
	}
}