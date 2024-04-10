/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("a.in", "r", stdin); freopen("a.out","w",stdout);
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for(int i = 0; i < n; i++){
		bool bol[10];
		for(int j = 0; j < 10; j++)
			bol[j] = false;
		int a;
		cin >> a;
		while (a > 0){
			bol[a % 10] = true;
			//cout << a << endl;
			a /= 10;
		}
		bool flag = false;
		for(int j = 0; j <= k; j++)
			if (!bol[j]){
				flag = true;
				break;
			}
		if (flag)
			continue;
		ans++;
	}
	cout << ans;
}