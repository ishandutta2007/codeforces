/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ar1[n], ar2[n];
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		int a = c - '0';
		ar1[i] = a;
	}
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		int a = c - '0';
		ar2[i] = a;
	}
	sort(ar1, ar1 + n);
	sort(ar2, ar2 + n);
	bool b1 = false, b2 = false;
	for(int i = 0; i < n; i++){
		b1 = (b1 || ar1[i] >= ar2[i]);
		b2 = (b2 || ar1[i] <= ar2[i]);
	}
	if(b1 && b2)
		cout << "NO";
	else
		cout << "YES";
}