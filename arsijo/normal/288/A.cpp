/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
#define ui unsigned int
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define mod % 1000000007

int main() {

	int n, k;
	cin >> n >> k;
	if(n == 1 && k == 1){
		cout << "a";
		return 0;
	}

	if(k == 1 || k > n){
		cout << "-1";
	}else{
		for(int i = 0; i < n - k + 2; i++)
			cout << (char) ('a' + (i % 2));
		for(int i = 2; i < k; i++)
			cout << (char) ('a' + i);
	}

}