/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld double
#define MAX 100001
#define si short int

int main() {

	ll a, b;
	cin >> a >> b;
	ll ans = 0;

	while(a > 0 && b > 0){
		if(a < b)
			swap(a, b);
		ans += a / b;
		a %= b;
	}

	cout << ans;

}