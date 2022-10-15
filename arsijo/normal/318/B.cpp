/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
	long long int ans = 0, a = 0;
	string s;
	cin >> s;
	int len = s.length() - 4;
	for(long long int i = 0; i < len; i++){
		string st = s.substr(i, 5);
		if (st == "heavy")
			a++;
		else if (st == "metal")
			ans += a;
	}
	cout << ans;
}