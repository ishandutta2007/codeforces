
// Problem : B. Phoenix and Puzzle
// Contest : Codeforces - Codeforces Global Round 14
// URL : https://codeforces.com/contest/1515/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		bool good = 0;
		if(N%4 == 0){
			int s = sqrt(N/4);
			if(s*s == N/4){
				good = 1;
			}
		}
		if(N%2 == 0){
			int s = sqrt(N/2);
			if(s*s == N/2){
				good = 1;
			}
		}
		cout << (good ? "YES\n" : "NO\n");
	}
}