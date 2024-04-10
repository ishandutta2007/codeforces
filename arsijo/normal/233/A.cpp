/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	if (n % 2 == 1){
		cout << -1;
		return 0;
	}
	for(int i = 0; i < (n / 2); i++){
		if (i % 2 == 0){
			cout << i + 2 << " ";
		}else{
			cout << i << " ";
		}
	}
	for(int i = (n / 2) + (n % 2); i < n; i++){
		if (i % 2 == 0){
			cout << i + 2 << " ";
		}else{
			cout << i << " ";
		}
	}
}