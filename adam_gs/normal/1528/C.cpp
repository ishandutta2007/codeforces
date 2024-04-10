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
const int LIM=3e5+7;
vector<int>V[LIM], S[LIM];
int pre[LIM], post[LIM], koniec[LIM], ind[LIM], lpre, lpost, ans, akt;
int synowie[4*LIM], ojcowie[4*LIM], N;
void post_i_pre(int x) {
	++lpre;
	pre[x]=lpre;
	ind[pre[x]]=x;
	for(auto i : S[x]) post_i_pre(i);
	++lpost;
	post[x]=lpost;
	koniec[x]=lpre;
}
bool czy_jest_syn(int x) {
	int l=pre[x]+N, r=koniec[x]+N;
	int ans=synowie[l]+synowie[r];
	while(l/2!=r/2) {
		if(l%2==0) ans+=synowie[l+1];
		if(r%2==1) ans+=synowie[r-1];
		l/=2; r/=2;
	}
	return ans>0;
}
void zmien_syna(int a, int x) {
	int v=pre[a]+N;
	synowie[v]=x;
	v/=2;
	while(v) {
		synowie[v]=synowie[2*v]+synowie[2*v+1];
		v/=2;
	}
}
void zmien_ojca(int a, int x) {
	int v=pre[a]+N;
	ojcowie[v]=x;
	v/=2;
	while(v) {
		ojcowie[v]=max(ojcowie[2*v], ojcowie[2*v+1]);
		v/=2;
	}
}
bool czy_jest_ojciec(int x) {
	int l=N, r=pre[x]+N-1;
	int ans=max(ojcowie[l], ojcowie[r]);
	while(l/2!=r/2) {
		if(l%2==0) ans=max(ans, ojcowie[l+1]);
		if(r%2==1) ans=max(ans, ojcowie[r-1]);
		l/=2; r/=2;
	}
	return ans>post[x];
}
int usun_ojca(int x) {
	int l=N, r=pre[x]+N-1;
	vector<int>przedzialy;
	przedzialy.pb(l);
	przedzialy.pb(r);
	while(l/2!=r/2) {
		if(l%2==0) przedzialy.pb(l+1);
		if(r%2==1) przedzialy.pb(r-1);
		l/=2; r/=2;
	}
	int ma=0;
	for(auto i : przedzialy) ma=max(ma, ojcowie[i]);
	for(auto i : przedzialy) if(ojcowie[i]==ma) {
		int v=i;
		while(v<N) {
			v*=2;
			if(ojcowie[v]<ojcowie[v+1]) ++v;
		}
		return ind[v-N];
	}
}
void DFS(int x) {
	if(czy_jest_syn(x)) {
		for(auto i : V[x]) DFS(i);
		return;
	}
	vector<int>usuniete;
	while(czy_jest_ojciec(x)) {
		int jaki=usun_ojca(x);
		usuniete.pb(jaki);
		zmien_ojca(jaki, 0);
		--akt;
		zmien_syna(jaki, 0);
	}
	zmien_ojca(x, post[x]);
	zmien_syna(x, 1);
	++akt;
	ans=max(ans, akt);
	for(auto i : V[x]) DFS(i);
	zmien_syna(x, 0);
	zmien_ojca(x, 0);
	--akt;
	for(auto i : usuniete) {
		zmien_ojca(i, post[i]);
		zmien_syna(i, 1);
		++akt;
	}
}
void solve() {
	int n;
	cin >> n;
	rep(i, n) {
		V[i].clear();
		S[i].clear();
		post[i]=pre[i]=ind[i+1]=0;
	}
	lpre=lpost=ans=akt=0;
	N=1;
	while(N<=n) N*=2;
	rep(i, 2*N) synowie[i]=ojcowie[i]=0;
	rep(i, n-1) {
		int a;
		cin >> a; --a;
		V[a].pb(i+1);
	}
	rep(i, n-1) {
		int a;
		cin >> a; --a;
		S[a].pb(i+1);
	}
	post_i_pre(0);
	DFS(0);
	cout << ans << '\n';
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int _;
	cin >> _;
	while(_--) solve();
}