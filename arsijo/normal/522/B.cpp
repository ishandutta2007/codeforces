/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define mod % 1000000007


int main() {

	int n;
	cin >> n;

	ll w = 0;

	ll a[n], b[n], m = 0, mI = 0, m2 = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		w += a[i];
		if(b[i] > m){
			m2 = m;
			m = b[i];
			mI = i;
		}else if (b[i] > m2){
			m2 = b[i];
		}
	}

	for(int i = 0; i < n; i++){
		cout << (w - a[i]) * (i == mI ? m2 : m) << " ";
	}

}