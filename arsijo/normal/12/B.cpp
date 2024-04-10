/*
 *      Author: arsijo;
 */

#include <bits/stdc++.h>
using namespace std;
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
//#define files(x) freopen(x ".dat", "r", stdin); freopen(x ".sol", "w", stdout);
#define input freopen("input.txt", "r", stdin);
#define ll long long
#define x first
#define y second
#define sync ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ms(x) memset(x, 0, sizeof(x));

void check(string s1, string s2){
	cout << (s1 == s2 ? "OK" : "WRONG_ANSWER");
}

int main() {

	string s;
	cin >> s;

	string ans;
	cin >> ans;

	if(s == "0"){
		check("0", ans);
		return 0;
	}

	int ar[10];
	ms(ar);

	string st = "";

	for(int i = 0; i < s.length(); i++){
		int g = s[i] - '0';
		ar[g]++;
	}

	for(int i = 1; i < 10; i++)
		if(ar[i]){
			st += ('0' + i);
			ar[i]--;
			break;
		}

	for(int i = 0; i < 10; i++)
		while(ar[i]--)
			st += ('0' + i);

	check(st, ans);

}