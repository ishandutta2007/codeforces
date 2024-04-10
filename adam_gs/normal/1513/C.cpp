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
const int LIM=2e5+17;
const ll MOD=1e9+7;
ll T[LIM], akt[10];
void solve() {
	int n, m;
	cin >> n >> m;
	ll ans=0;
	while(n) {
		ans+=T[m+n%10];
		ans%=MOD;
		n/=10;
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	akt[0]=T[0]=1;
	for(int i=1; i<LIM; ++i) {
		ll tmp[10];
		rep(j, 10) tmp[j]=0;
		rep(j, 9) tmp[j+1]=akt[j];
		tmp[0]+=akt[9];
		tmp[1]+=akt[9];
		rep(j, 10) {
			akt[j]=tmp[j]%MOD;
			T[i]+=akt[j];
			T[i]%=MOD;
		}
	}
	int _;
	cin >> _;
	while(_--) solve();
}