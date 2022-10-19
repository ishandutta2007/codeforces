#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
const int LIM=2e5+7;
vector<int>V[LIM];
ll sil[LIM], osil[LIM], ile[LIM], ans, n, k;
ll pot(ll a, ll b) {
	ll c=1;
	while(b) {
		if(b&1) c=(c*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return c;
}
ll C(ll a, ll b) {
	if(a<b) return 0;
	return (((sil[a]*osil[b])%MOD)*osil[a-b])%MOD;
}
void DFS(int x, int o) {
	ile[x]=1;
	for(auto i : V[x]) if(i!=o) {
		DFS(i, x);
		ile[x]+=ile[i];
	}
	ll p=C(ile[x], k);
	for(auto i : V[x]) if(i!=o) p=(p-C(ile[i], k)+MOD)%MOD;
	p=(p*ile[x])%MOD;
	p=(p*(n-ile[x]))%MOD;
	ans=(ans+p)%MOD;
	p=0;
	for(auto i : V[x]) if(i!=o) p=(p+C(ile[i], k))%MOD;
	p=(p+C(n-ile[x], k))%MOD;
	for(auto i : V[x]) if(i!=o) {
		p=(p-C(ile[i], k)+MOD)%MOD;
		ll a=C(n-ile[i], k);
		a=(a-p+MOD)%MOD;
		a=(a*(n-ile[i]))%MOD;
		a=(a*ile[i])%MOD;
		ans=(ans+a)%MOD;
		p=(p+C(ile[i], k))%MOD;
	}
	ll a=C(n, k);
	a=(a-p+MOD)%MOD;
	a=(a*n)%MOD;
	ans=(ans+a)%MOD;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	sil[0]=osil[0]=1;
	for(ll i=1; i<=n; ++i) {
		sil[i]=(sil[i-1]*i)%MOD;
		osil[i]=pot(sil[i], MOD-2);
	}
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	DFS(0, 0);
	cout << ans << '\n';
}