#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n;
	cin >> n;
	int T[n][5];
	rep(i, n) rep(j, 5) cin >> T[i][j];
	int k=0;
	for(int i=1; i<n; ++i) {
		int sum=0;
		for(int j=0; j<5; ++j) {
			sum+=T[i][j]<T[k][j];
		}
		if(sum>=3) k=i;
	}
	for(int i=0; i<n; ++i) {
		if(i==k) continue;
		int sum=0;
		for(int j= 0; j<5; ++j) {
			sum+=T[k][j]<T[i][j];
		}
		if(sum<3) {
			cout << "-1\n";
			return;
		}
	}
	cout << k+1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}