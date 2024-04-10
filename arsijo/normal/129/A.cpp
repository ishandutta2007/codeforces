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

	int n;
	cin >> n;
	int ar[2];
	ms(ar);
	int m = 0;
	while(n--){
		int a;
		cin >> a;
		ar[a % 2]++;
		m += a;
	}

	cout << ar[m % 2];

}