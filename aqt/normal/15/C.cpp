
// Problem : C. Industrial Nim
// Contest : Codeforces Beta Round #15
// URL : https://codeforces.com/contest/15/problem/C
// Memory Limit : 64 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	long long tot = 0;
	while(N--){
		long long x, m;
		cin >> x >> m;
		while(x%4 && m){
			tot ^= x;
			x++;
			m--;
		}
		x += m-1;
		m %= 4;
		while(m--){
			tot ^= x;
			x--;
		}
	}
	cout << (tot ? "tolik" : "bolik") << "\n";
}