
// Problem : E. Count The Blocks
// Contest : Educational Codeforces Round 84 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1327/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

long long N;
long long MOD = 998244353;
long long pows[200005];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	pows[0] = 1;
	for(int i = 1; i<=N; i++){
		pows[i] = pows[i-1] * 10;
		pows[i] %= MOD;
	}
	for(int i = 1; i<N-1; i++){
		long long tot = 180 * pows[N-(i+1)];
		tot += 810 * pows[N-(i+2)] %MOD * (N-(i+1)) %MOD; 
		tot %= MOD;
		cout << tot << " ";
	}
	if(N != 1){
		cout << 180 << " ";
	}
	cout << 10 << "\n";
}