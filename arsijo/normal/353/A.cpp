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

	int x[n], y[n], s1 = 0, s2 = 0;

	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		x[i] = a % 2;
		y[i] = b % 2;
		s1 += x[i];
		s2 += y[i];
	}

	if(s1 % 2 != s2 % 2){
		cout << -1;
	}else if (s1 % 2 == 0){
		cout << 0;
	}else{
		for(int i = 0; i < n; i++){
			if(x[i] != y[i]){
				cout << 1;
				return 0;
			}
		}
		cout << -1;
	}


}