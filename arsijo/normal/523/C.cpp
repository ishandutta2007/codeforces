/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define mod % 1000000007

int main() {

	string t, s;
	cin >> s >> t;
	int pos = 0;
	int i;
	for (i = 0; i < t.length() && pos < s.length(); i++) {
		if (s[pos] == t[i])
			pos++;
		if (pos == s.length())
			break;
	}
	int j;
	pos = s.length() - 1;
	for(j = t.length() - 1; j >= 0 && pos < s.length(); j--){
		if(s[pos] == t[j])
			pos--;
		if(pos < 0)
			break;
	}
	if(i >= j){
		cout << 0;
	}else{
		cout << j - i;
	}

}