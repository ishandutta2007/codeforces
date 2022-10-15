/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
//#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

int main() {

	string s, t;
	cin >> s >> t;
	int a[100], b[100], size = s.length();

	for(int i = 0; i < size; i++){
		a[i] = s[i] - 'a';
		b[i] = t[i] - 'a';
	}

	int g = 1;

	for(int i = size - 1; i >= 0; i--){
		a[i] += g;
		g = a[i] / 26;
		a[i] %= 26;
	}

	for(int i = 0; i < size; i++){
		if(a[i] != b[i]){
			for(int j = 0; j < size; j++){
				char c = a[j] + 'a';
				cout << c;
			}
			return 0;
		}
	}

	cout << "No such string";

}