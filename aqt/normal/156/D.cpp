
// Problem : D. Clues
// Contest : Codeforces - Codeforces Round #110 (Div. 1)
// URL : https://codeforces.com/contest/156/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

using namespace std;

int N, M;
long long MOD;
int sz[100005];
int dsu[100005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> MOD;
	fill(sz+1,sz+1+N, 1);
	iota(dsu+1, dsu+1+N, 1);
	int C = N;
	while(M--){
		int a, b;
		cin >> a >> b;
		if(getrt(a) != getrt(b)){
			sz[getrt(b)] += sz[getrt(a)];
			dsu[getrt(a)] = getrt(b);
			C--;
		}
	}
	if(C == 1){
		cout << 1%MOD;
		return 0;
	}
	C -= 2;
	long long ans = 1;
	for(int i = 1; i<=C; i++){
		ans *= N;
		ans %= MOD;
	}
	for(int i = 1; i<=N; i++){
		if(getrt(i) == i){
			ans *= sz[i];
			ans %= MOD;
		}
	}
	cout << ans;
}