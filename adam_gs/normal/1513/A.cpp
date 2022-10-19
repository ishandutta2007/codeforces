#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
	int n, k;
	cin >> n >> k;
	if((n-1)/2<k) {
		cout << -1 << '\n';
		return;
	}
	int a=1, b=n;
	rep(i, 2*k) {
		if(i%2==0) {
			cout << a << " ";
			++a;
		} else {
			cout << b << " ";
			--b;
		}
	}
	while(b>=a) {
		cout << b << " ";
		--b;
	}
	cout << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}