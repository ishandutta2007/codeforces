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

int main() {

	string s;
	cin >> s;

	int ans = 0, g = 0;

	for(int i = 0; i < s.length(); i++){
		if(s[i] == '('){
			g++;
		}else{
			g--;
			if(g >= 0){
				ans += 2;
			}else{
				g = 0;
			}
		}
	}

	cout << ans;

}