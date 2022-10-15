/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
const int mod = 1000000007;

int main() {

	string s;
	cin >> s;
	int a = s[0] - '0';
	if(a > 4 && a != 9)
		cout << 9 - a;
	else
		cout << a;
	for(int i = 1; i < s.length(); i++){
		a = s[i] - '0';
		cout << min(a, 9 - a);
	}

}