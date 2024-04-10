/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	ll n, m;
	cin >> n >> m;

	ll a = n;

	for(int i = 0; i < 100; i++){
		if(a == m){
			cout << "YES\n" << i << endl;
			return 0;
		}
		if(a > m){
			cout << "NO";
			return 0;
		}
		a *= n;
	}

}