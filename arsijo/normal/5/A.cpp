/*
 *      Author: arsijo;
 *      made in Ukraine;
 */

#include <bits/stdc++.h>
using namespace std;

int main(){

	string s;
	int users = 0, ans = 0;
	while(getline(cin, s)){
		if (s[0] == '+')
			users++;
		else if (s[0] == '-')
			users--;
		else
			ans += (s.size() - s.find(':') - 1) * users;
	}
	cout << ans;

}