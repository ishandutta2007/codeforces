/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	string s, t;
	cin >> s >> t;
	int j = 0;
	for(int i = 0; i < t.length(); i++){
		if (t[i] == s[j])
			j++;
	}
	cout << j + 1;

}