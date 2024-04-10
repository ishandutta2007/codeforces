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
	ll k, x;
	cin >> k >> x;
	if(x>k*(k+1)/2) {
		x-=k*(k+1)/2;
		ll po=0, ko=k-1;
		while(po<ko) {
			ll sr=(po+ko)/2;
			if(k*sr-sr*(sr+1)/2<x) po=sr+1; else ko=sr;
		}
		cout << po+k << '\n';
		return;
	}
	ll po=1, ko=k;
	while(po<ko) {
		ll sr=(po+ko)/2;
		if(sr*(sr+1)/2<x) po=sr+1; else ko=sr;
	}
	cout << po << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}