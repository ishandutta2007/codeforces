
// Problem : E. PolandBall and White-Red graph
// Contest : Codeforces - 8VC Venture Cup 2017 - Elimination Round
// URL : https://codeforces.com/contest/755/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, K;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	if(N <= 3 || (K != 2) && (K != 3)){
		cout << -1 << "\n";
		return 0;
	}
	else if(N == 4){
		if(K == 3){
			cout << 3 << "\n";
			cout << 1 << " " << 2 << "\n";
			cout << 2 << " " << 3 << "\n";
			cout << 3 << " " << 4 << "\n";
			return 0;
		}
		else{
			cout << -1;
			return 0;
		}
	}
	else if(K == 2){
		cout << N-1 << "\n";
		for(int i = 1; i<N; i++){
			cout << i << " " << i+1 << "\n";
		}
		return 0;
	}
	else{
		cout << N-1 << "\n";
		cout << 1 << " " << 2 << "\n";
		cout << 2 << " " << 3 << "\n";
		for(int i = 4; i<=N; i++){
			cout << 3 << " " << i << "\n";
		}
	}
}