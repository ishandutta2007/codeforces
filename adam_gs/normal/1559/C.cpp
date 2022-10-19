#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
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
	int n;
	cin >> n;
	int T[n];
	rep(i, n) cin >> T[i];
	if(T[0]==1) {
		cout << n+1 << " ";
		rep(i, n) cout << i+1 << " ";
		cout << '\n';
		return;
	}
	if(T[n-1]==0) {
		rep(i, n) cout << i+1 << " ";
		cout << n+1 << '\n';
		return;
	}
	rep(i, n-1) {
		if(T[i]==0 && T[i+1]==1) {
			rep(j, i+1) {
				cout << j+1 << " ";
			}
			cout << n+1 << " ";
			for(int j=i+1; j<n; ++j) {
				cout << j+1 << " ";
			}
			cout << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}