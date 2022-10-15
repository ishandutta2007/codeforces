/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
//#define x first
//#define y second
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	int n;
	cin >> n;
	if(n == 3)
		cout << 1;
	if(n == 1)
		cout << 2;
	if(n == 4)
		cout << 2;
	if(n == 2)
		cout << 3;
	if(n == 5)
		cout << 1;

}