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
#define ld long double

int main() {

	int n, m;
	cin >> n >> m;

	if(n >= m){
		cout << n - m;
		return 0;
	}

	int ans = 0;

	while(n < m){
		if(m % 2){
			m++;
			m /= 2;
			ans += 2;
		}else{
			m /= 2;
			ans++;
		}
	}

	cout << ans + n - m;

}