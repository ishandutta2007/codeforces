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
	int n, l, r, k;
	cin >> n >> l >> r >> k;
	int T[n], ans=0;
	rep(i, n) cin >> T[i];
	sort(T, T+n);
	rep(i, n) if(T[i]>=l && T[i]<=r && T[i]<=k) {
		++ans;
		k-=T[i];
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}