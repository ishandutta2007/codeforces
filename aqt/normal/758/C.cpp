
// Problem : C. Unfair Poll
// Contest : Codeforces - Codeforces Round #392 (Div. 2)
// URL : https://codeforces.com/contest/758/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long N, M, K, X, Y;

long long calc(int x, int y){
	if(N == 1){
		return K/M + (K%M > y);
	}
	else{
		long long P = (2*N-2)*M;
		long long ret = ((x != 0 && x != N-1)+1)*(K/P);
		if(x == 0){
			return ret + (K%P > y);
		}
		else if(x == N-1){
			return ret + (K%P > x*M+y);
		}
		else{
			return ret + (K%P > x*M+y) + (K%P > (2*N-x-2)*M+y);
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K >> X >> Y;
	X--, Y--;
	long long mn = LLONG_MAX/2, mx = 0;
	for(int i = 0; i<N; i++){
		for(int j = 0; j<M; j++){
			//cout << i << " " << j << " " << calc(i, j) << "\n";
			mn = min(mn, calc(i, j));
			mx = max(mx, calc(i, j));
		}
	}
	cout << mx << " " << mn << " " << calc(X, Y);
}