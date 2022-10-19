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
	string x;
	cin >> x;
	for(int i=1; i<n; ++i) {
		if(x[i]=='?') {
			if(x[i-1]=='R') {
				x[i]='B';
			} else if(x[i-1]=='B') {
				x[i]='R';
			}
		}
	}
	for(int i=n-2; i>=0; --i) {
		if(x[i]=='?') {
			if(x[i+1]=='R') x[i]='B';
			else if(x[i+1]=='B') x[i]='R';
		}
	}
	if(x[0]=='?') {
		rep(i, n) {
			if(i%2==0) x[i]='R'; else x[i]='B';
		}
	}
	cout << x << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}