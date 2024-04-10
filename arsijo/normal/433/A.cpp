/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin >> n;
	int a = 0, b = 0;
	for(int i = 0; i < n; i++){
		int c;
		cin >> c;
		if (c == 100)
			a++;
		else
			b++;
	}
	if (a == 0 && b % 2 == 1)
		cout << "NO";
	else if (a % 2 == 0)
		cout << "YES";
	else
		cout << "NO";
}