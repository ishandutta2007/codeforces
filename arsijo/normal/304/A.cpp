/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){

	int n, ans;
	cin >> n;
	ans = 0;
	for(int i = 1; i < n; i++){
		for(int j = i; j < n; j++){
			int a = (int) sqrt(i * i + j * j);
			if (i * i + j * j == a * a && a <= n)
				ans++;
		}
	}

	cout << ans;

}