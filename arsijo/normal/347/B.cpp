/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	int n;
	cin >> n;
	int ar[n];
	for(int i = 0; i < n; i++){
		cin >> ar[i];
	}
	int ans = 0;
	bool b = false;
	for(int i = 0; i < n; i++){
		if (ar[i] == i)
			ans++;
		else{
			if (ar[ar[i]] == i)
				b = true;
		}
	}
	if (ans != n && !b){
		ans++;
	}
	if(b)
		ans += 2;
	cout << ans;
}