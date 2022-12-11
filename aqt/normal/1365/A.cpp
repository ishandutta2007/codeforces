
// Problem : A. Matrix Game
// Contest : Codeforces - Codeforces Round #648 (Div. 2)
// URL : https://codeforces.com/contest/1365/problem/A
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
		int N, M;
		cin >> N >> M;
		set<int> r, c;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				int k;
				cin >> k;
				if(k){
					r.insert(i);
					c.insert(j);
				}
			}
		}
		int a = min(N-r.size(), M-c.size());
		if(a%2 == 0){
			cout << "Vivek\n";
		}
		else{
			cout << "Ashish\n";
		}
	}
}