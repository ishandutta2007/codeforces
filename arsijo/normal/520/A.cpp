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

bool ar[26];
int ans;

void add(char c){
	int g = c - 'a';
	if(!(g >= 0 && g < 26)){
		g = c - 'A';
	}
	if(!ar[g]){
		ar[g] = true;
		ans++;
	}
}

int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	ms(ar);
	ans = 0;

	for(int i = 0; i < n; i++)
		add(s[i]);

	cout << (ans == 26 ? "YES" : "NO");

}