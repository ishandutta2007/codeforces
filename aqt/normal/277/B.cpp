
// Problem : B. Set of Points
// Contest : Codeforces - Codeforces Round #170 (Div. 1)
// URL : https://codeforces.com/contest/277/problem/B
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	if(M == 3){
		if(N >= 5){
			cout << -1 << "\n";
			return 0;
		}
		cout << "0 1\n -1 -1\n 1 -1\n";
		if(N == 4){
			cout << "0 0\n";
		}
		return 0;
	}
	for(int i = 1; i<=M; i++){
		cout << i << " " << i*i+10000000 << "\n";
	}
	for(int i = 1; i<=N-M; i++){
		cout << i << " " << -i*i-10000000 << "\n";
	}
}