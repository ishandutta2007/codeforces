
// Problem : C. Ayoub's function
// Contest : Codeforces Round #619 (Div. 2)
// URL : https://codeforces.com/contest/1301/problem/C
// Memory Limit : 256.000000 MB 
// Time Limit : 1000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include <bits/stdc++.h>

using namespace std;

long long f(long long N){
	return N*(N+1)/2;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		long long N, M;
		cin >> N >> M;
		long long G = (N-M)/(M+1);
		long long R = (N-M)%(M+1);
		long long A = f(N);
		A -= R*f(G+1);
		A -= (M+1-R)*f(G);
		cout << A << "\n";
	}
}