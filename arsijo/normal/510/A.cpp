/*
 *      Author: arsijo;
 */
#include <bits/stdc++.h>
using namespace std;
#define input freopen("input.txt", "r", stdin);
#define files(x) freopen(x ".in", "r", stdin); freopen(x ".out", "w", stdout);
#define sync ios_base::sync_with_stdio(0); cin.tie(0);
#define ll long long

int main() {
	string s1 = "", s2 = "";
	int a, b;
	cin >> a >> b;
	for(int i = 0; i < b; i++)
		s1 = s1 + "#";
	for(int i = 1; i < b; i++)
		s2 = s2 + ".";
	for(int i = 0; i < a; i++){
		if(i % 2){
			if(i / 2 % 2){
				cout << "#" << s2 << endl;
			}else{
				cout << s2  << "#" << endl;
			}
		}else{
			cout << s1 << endl;
		}
	}
}