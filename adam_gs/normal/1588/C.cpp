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
const int LIM=3e5+7;
const ll INF=1e18+7;
ll T[LIM], ans;
void dziel(int l, int r) {
	if(l==r) {
		if(!T[l]) ++ans;
		return;
	}
	int mid=(l+r)/2;
	map<ll,ll>mp;
	ll akt=0, mi[2];
	mi[0]=mi[1]=INF;
	for(int i=mid; i>=l; --i) {
		if((mid-i)%2==0) akt+=T[i];
		else akt-=T[i];
		mi[i%2]=min(mi[i%2]+T[i], T[i]);
		mi[(i+1)%2]-=T[i];
		if(min(mi[0], mi[1])>=0) ++mp[akt];
	}
	akt=0;
	mi[0]=mi[1]=INF;
	for(int i=mid+1; i<=r; ++i) {
		if((i-mid-1)%2==0) akt+=T[i];
		else akt-=T[i];
		mi[i%2]=min(mi[i%2]+T[i], T[i]);
		mi[(i+1)%2]-=T[i];
		if(min(mi[0], mi[1])>=0) ans+=mp[akt];
	}
	dziel(l, mid);
	dziel(mid+1, r);
}
void solve() {
	ans=0;
	int n;
	cin >> n;
	rep(i, n) cin >> T[i];
	dziel(0, n-1);
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}