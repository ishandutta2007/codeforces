#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=998244353;
const int LIM=15e4+7, K=250;
vector<int>V[LIM];
int pre[LIM], post[LIM], ile[LIM], oc[LIM], duzy[LIM], ilesyn[LIM], lpre, n;
ll ilemi[LIM], ilesynom[LIM], pkt[LIM], blok[LIM];
ll pot(ll a, ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b/=2;
	}
	return ans;
}
void DFS(int x, int o) {
	oc[x]=o;
	++lpre;
	pre[x]=lpre;
	ile[x]=1;
	for(auto i : V[x]) if(i!=o) {
		DFS(i, x);
		ile[x]+=ile[i];
	}
	post[x]=lpre;
}
void DFS2(int x) {
	if(!x) duzy[x]=-1;
	else if(V[oc[x]].size()>K) {
		duzy[x]=oc[x];
		ilesyn[x]=ile[x];
	} else {
		duzy[x]=duzy[oc[x]];
		ilesyn[x]=ilesyn[oc[x]];
	}
	for(auto i : V[x]) if(i!=oc[x]) DFS2(i);
}
void dodaj(int l, int r, ll x) {
	--l; --r;
	pkt[l]=(pkt[l]+x)%MOD;
	blok[l/K]=(blok[l/K]+x)%MOD;
	pkt[r+1]=(pkt[r+1]-x+MOD)%MOD;
	blok[(r+1)/K]=(blok[(r+1)/K]-x+MOD)%MOD;
}
ll pytaj(int x) {
	--x;
	ll ans=0, p=K-1;
	while(p<=x) {
		ans=(ans+blok[p/K])%MOD;
		p+=K;
	}
	p-=K-1;
	while(p<=x) {
		ans=(ans+pkt[p])%MOD;
		++p;
	}
	return ans;
}
void upd(int x, ll d) {
	dodaj(pre[0], post[0], (d*ile[x])%MOD);
	dodaj(pre[x], post[x], MOD-((d*ile[x])%MOD));
	ilemi[x]=(ilemi[x]+d*n)%MOD;
	if(V[x].size()<=K) {
		for(auto i : V[x]) if(i!=oc[x]) dodaj(pre[i], post[i], (d*(n-ile[i]))%MOD);
	} else ilesynom[x]=(ilesynom[x]+d)%MOD;
}
ll cnt(int x) {
	ll ans=ilemi[x];
	ans=(ans+pytaj(pre[x]))%MOD;
	while(duzy[x]!=-1) {
		ans=(ans+ilesynom[duzy[x]]*(n-ilesyn[x]))%MOD;
		x=duzy[x];
	}
	return (ans*pot(n, MOD-2))%MOD;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int q;
	cin >> n >> q;
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	DFS(0, 0);
	DFS2(0);
	while(q--) {
		int t, x;
		cin >> t >> x; --x;
		if(t==1) {
			ll d;
			cin >> d;
			upd(x, d);
		} else cout << cnt(x) << '\n';
	}
}