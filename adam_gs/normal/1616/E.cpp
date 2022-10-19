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
const ll INF=1e18+7;
const int LIM=1e5+7;
ll tr[4*LIM], N, li[26];
vector<ll>V[26];
void upd(int l, int r) {
	l+=N; r+=N;
	--tr[l];
	if(l!=r) --tr[r];
	while(l/2!=r/2) {
		if(l%2==0) --tr[l+1];
		if(r%2==1) --tr[r-1];
		l/=2; r/=2;
	}
}
ll cnt(int v) {
	v+=N;
	ll ans=0;
	while(v) {
		ans+=tr[v];
		v/=2;
	}
	return ans;
}
void solve() {
	int n;
	string a, b;
	cin >> n >> a >> b;
	N=1;
	while(N<n) N*=2;
	rep(i, N) tr[N+i]=i;
	for(int i=N-1; i; --i) tr[i]=0;
	rep(i, 26) {
		li[i]=0;
		V[i].clear();
	}
	string c=a;
	sort(all(c));
	bool ok=false;
	rep(i, n) {
		if(c[i]<b[i]) ok=true;
		if(c[i]!=b[i]) break;
	}
	if(!ok) {
		cout << -1 << '\n';
		return;
	}
	rep(i, n) V[a[i]-'a'].pb(i);
	ll ans=INF, akt=0;
	rep(i, n) {
		rep(j, b[i]-'a') if(li[j]<V[j].size()) ans=min(ans, akt+cnt(V[j][li[j]]));
		if(li[b[i]-'a']==V[b[i]-'a'].size()) break;
		akt+=cnt(V[b[i]-'a'][li[b[i]-'a']]);
		upd(V[b[i]-'a'][li[b[i]-'a']], N-1);
		++li[b[i]-'a'];
	}
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _=1;
	cin >> _;
	while(_--) solve();
}