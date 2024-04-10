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
const int LIM=2e7+7;
vector<ll>pi;
ll T[LIM], ile[LIM], dp[LIM], cp[LIM];
void cnt(vector<pair<int,int>>&T, int i, int x) {
	if(i==T.size()) {
		++ile[x];
		return;
	}
	rep(j, T[i].nd+1) {
		cnt(T, i+1, x);
		x*=T[i].st;
	}
}
void solve() {
	for(int i=2; i<LIM; ++i) {
		if(cp[i]) continue;
		pi.pb(i);
		for(int j=2*i; j<LIM; j+=i) cp[j]=1;
	}
	int n;
	cin >> n;
	rep(i, n) {
		int a;
		cin >> a;
		vector<pair<int,int>>T;
		for(int j=0; pi[j]*pi[j]<=a; ++j) {
			int l=0;
			while(a%pi[j]==0) {
				a/=pi[j];
				++l;
			}
			if(l) T.pb({pi[j], l});
		}
		if(a>1) T.pb({a, 1});
		cnt(T, 0, 1);
	}
	ll ans=0;
	for(ll i=1; i<LIM; ++i) {
		dp[i]+=i*ile[i];
		ans=max(ans, dp[i]);
		for(int j=0; j<pi.size() && pi[j]*i<LIM; ++j) {
			dp[i*pi[j]]=max(dp[i*pi[j]], dp[i]-ile[i*pi[j]]*i);
		}
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	//cin >> _;
	while(_--) solve();
}