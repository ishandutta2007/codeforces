/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;

int main() {

	int n;
	cin >> n;
	int ar[7];
	for(int i = 0; i < 7; i++){
		cin >> ar[i];
	}

	for(int i = 0; i < 7000; i++){
		n -= ar[i % 7];
		if(n <= 0){
			cout << (i % 7) + 1;
			return 0;
		}
	}
}