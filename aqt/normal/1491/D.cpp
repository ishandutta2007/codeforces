// Problem : D. Zookeeper and The Infinite Zoo
// Contest : Codeforces - Codeforces Global Round 13
// URL : https://codeforces.com/contest/1491/problem/D
// Memory Limit : 256 MB
// Time Limit : 3000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		long long a, b;
		cin >> a >> b;
		bool good = 1;
		if(a > b){
			good = 0;			
		}
		for(int k = 30; k >= 0; k--){
			if(b >> k & 1){
				for(int t = k; t >= 0; t--){
					if(a >> t & 1){
						a ^= (1 << t);
						break;
					}	
					else if(t == 0){
						good = 0;
					}
				}
			}
		}
		if(!good){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
		}
	}
}