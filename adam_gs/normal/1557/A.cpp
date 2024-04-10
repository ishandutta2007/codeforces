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
	ld T[n];
	rep(i, n) {
	    int p;
	    cin >> p;
	    T[i]=p;
	}
	sort(T, T+n);
	ld a=0;
	rep(i, n-1) a+=T[i];
	ld x=n-1;
	a/=x;
	a+=T[n-1];
	cout << fixed << setprecision(6) << a << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}