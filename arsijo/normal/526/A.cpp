/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define output freopen("output.txt", "w", stdout);
#define io input; output;
#define ll long long
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));
#define ld long double
#define sqr(a) ((a) * (a))
#define si short int
#define endl "\n"
#define mod % 1743
const ld E = 1e-9;
const int MAX = 100000;

int main() {

	int n;
	cin >> n;

	bool bol[n];
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		bol[i] = c == '*';
	}

	for(int i = 0; i < n; i++){
		for(int j = 1; bol[i] && i + j * 4 < n; j++){
			if(bol[i + j] && bol[i + j * 2] && bol[i + j * 3] && bol[i + j * 4]){
				cout << "yes";
				return 0;
			}
		}
	}
	cout << "no";
}