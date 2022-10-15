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

string s;
bool bol = false;

void print(int l, int r){
	if(bol)
		cout << "-";
	bol = true;
	for(int i = l; i <= r; i++)
		cout << s[i];
}

int main() {

	int n;
	cin >> n;
	cin >> s;
	if(s.length() % 2 == 0){
		for(int i = 0; i < s.length() / 2; i++)
			print(i * 2, i * 2 + 1);
	}else if (s.length() % 3 == 0){
		for(int i = 0; i < s.length() / 3; i++)
			print(i * 3, i * 3 + 2);
	}else{
		int pos = 0;
		while((s.length() - pos) % 3 != 0){
			print(pos, pos + 1);
			pos += 2;
		}
		int g = s.length() - pos;
		g /= 3;
		for(int i = 0; i < g; i++)
			print(pos + i * 3, pos + i * 3 + 2);
	}

}