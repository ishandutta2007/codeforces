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

	ll n, m;

	cin >> n >> m;

	if(n > m)
		cout << "First";
	else
		cout << "Second";

}