/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

void goHome(){
	cout << "NO";
	exit(0);
}

int main() {

	string s[3];
	for(int i = 0; i < 3; i++)
		cin >> s[i];

	for(int i = 0; i < 3; i++)
		if(s[0][i] != s[2][2 - i])
			goHome();

	if(s[1][0] != s[1][2])
		goHome();

	cout << "YES";

}