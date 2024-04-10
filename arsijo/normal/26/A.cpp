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

bool check(int a){
	int g = 0;
	for(int i = 2; i <= sqrt(a); i++){
		if(a % i == 0){
			g++;
			while(a % i == 0)
				a/= i;
		}
	}
	if(a != 1)
		g++;
	return g == 2;
}

int main() {

	int n;
	cin >> n;

	int ans = 0;

	for(int i = 6; i <= n; i++){
		if(check(i))
			ans++;
	}

	cout << ans;

}