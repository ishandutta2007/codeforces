/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	int ar[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar, ar + n);
	double ans = 0;
	for(int i = n - 1; i >= 0; i--){
		double a = pow(ar[i], 2) * M_PI;
		if(i % 2 == n % 2){
			ans -= a;
		}else{
			ans += a;
		}
	}

	cout << ans;

}