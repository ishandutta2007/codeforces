/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);

	int k;
	cin >> k;
	char ar[16];
	for(int i = 0; i < 16; i++)
		cin >> ar[i];
	sort(ar, ar + 16);
	int a = 1;
	for(int i = 1; i < 16; i++){
		if (ar[i] == ar[i-1])
			a++;
		else{
			if (a > 2 * k && ar[i-1] != '.'){
				cout << "NO";
				return 0;
			}
			a = 1;
		}
	}
	if (a > 2 * k && ar[15] != '.'){
		cout << "NO";
	}else{
		cout << "YES";
	}
}