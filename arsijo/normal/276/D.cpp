/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld double
#define MAX 500
#define si short int

int main() {

	//io;
	ll l, r;
	cin >> l >> r;
	int i;
	for(i = (int) log2(r); i >= 0 && !((l ^ r) & (1ll << i)); i--);
	cout << (1ll << (i + 1)) - 1;
}