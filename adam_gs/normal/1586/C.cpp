#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n, m;
	cin >> n >> m;
	string T[n];
	rep(i, n) cin >> T[i];
	int A[n+1][m+1];
	rep(i, n+1) rep(j, m+1) A[i][j]=0;
	rep(i, n) rep(j, m) {
		if(i && j && T[i][j-1]=='X' && T[i-1][j]=='X') {
			++A[i+1][j+1];
		}
		A[i+1][j+1]+=A[i][j+1]+A[i+1][j]-A[i][j];
	}
	int q;
	cin >> q;
	while(q--) {
		int x1, x2;
		cin >> x1 >> x2;
		cout << (A[n][x2]-A[n][x1]>0?"NO":"YES") << '\n';
	}
}
int main() { 
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}