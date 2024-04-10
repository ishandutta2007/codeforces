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
	ll n, k, s;
	cin >> s >> n >> k;
	if(s<k) {
		cout << "NO\n";
		return;
	}
	if(s==k) {
	    cout << "YES\n";
	    return;
	}
	ll x=n/k;
	x*=k;
	x+=n;
	cout << (x<=s?"NO":"YES") << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}