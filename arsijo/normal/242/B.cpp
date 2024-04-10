/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	long a[n], b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}

	long m1 = a[0], m2 = b[0];

	for(int i = 1; i < n; i++){
		m1 = min(m1, a[i]);
		m2 = max(m2, b[i]);
	}

	for(int i = 0; i < n; i++){
		if (a[i] == m1 && b[i] == m2){
			cout << i + 1;
			return 0;
		}
	}
	cout << -1;
}