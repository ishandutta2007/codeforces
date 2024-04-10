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
const int LIM=1e5+7;
ll T[2*LIM];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i, 2*n) cin >> T[i];
	sort(T, T+2*n);
	ll ans=(T[n-1]-T[0])*(T[2*n-1]-T[n]);
	for(int i=n; i<2*n-1; ++i) ans=min(ans, (T[2*n-1]-T[0])*(T[i]-T[i-n+1]));
	cout << ans << '\n';
}