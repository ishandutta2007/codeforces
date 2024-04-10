//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define ms(x) memset(x, 0, sizeof(x));
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define ll long long
#define ld long double
#define sqr(a) ( (a) * (a) )
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const ld E = 1e-9;
const int MAX = 1e9;


int main() {

	int n;
	cin >> n;

	string s, t;
	cin >> s >> t;

	int ans = 0;
	for(int i = 0; i < n; i++){
		int a = s[i] - '0', b = t[i] - '0';
		int c = abs(a - b);
		if(c > 5)
			c -= (c - 5) * 2;
		ans += c;
	}

	cout << ans;

}