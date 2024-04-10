/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("c.in", "r", stdin); freopen("c.out", "w", stdout);
	string s;
	cin >> s;
	int k;
	cin >> k;
	int ar[26], m = 0;
	for(int i = 0; i < 26; i++){
		cin >> ar[i];
		m = max(ar[i], m);
	}
	long long ans = 0;
	for(int i = 0; i < s.length(); i++){
		ans += ar[s[i] - 'a'] * (i + 1);
	}
	for(int i = 0; i < k; i++){
		ans += m * (s.length() + 1 + i);
	}
	cout << ans;
}