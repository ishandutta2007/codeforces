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
//#define x first
//#define y second
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

void pluss(string &s){
	for(ui i = 0; i < s.length(); i++){
		s[i] = ((s[i] - '0' + 1) % 10) + '0';
	}
}

void shift(string &s){
	char c = s[0];
	for(ui i = 0; i < s.length() - 1; i++)
		s[i] = s[i + 1];
	s[s.length() - 1] = c;
}

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	string ans = s;

	for(ui i = 0; i <= s.length(); i++){
		for(ui j = 0; j < 10; j++){
			pluss(s);
			if(s < ans)
				ans = s;

		}
		shift(s);
	}

	cout << ans;

}