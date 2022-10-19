#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") 
#pragma GCC option("arch=native","tune=native","no-zero-upper") 
#pragma GCC target("avx2","popcnt","rdrnd","bmi2")
#include<bits/stdc++.h>
template<typename A, typename B>
A& operator*=(A &a, const B &b) {
  a = a * b;
  return a;
}
template<typename A, typename B>
A& operator-=(A &a, const B &b) {
	a = a - b;
	return a;
}
template<typename A, typename B>
A& operator+=(A &a, const B &b) {
	a = a + b;
	return a;
}
template<typename A, typename B>
A& operator/=(A &a, const B &b) {
	a = a / b;
	return a;
}
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll MOD=1e9+7;
ll pot(ll a, ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=ans*a%MOD;
		b/=2;
		a=a*a%MOD;
	}
	return ans;
}
struct mint {
	mint(ll x): x(x) {}
	mint() {}
	ll x;
};
ostream& operator<<(ostream &p, mint a) {
	p << a.x;
	return p;
}
istream& operator>>(istream &p, mint &a) {
	p >> a.x;
	return p;
}
mint operator+(mint a, mint b) {
	return (a.x+b.x)%MOD;
}
mint operator-(mint a, mint b) {
	return (a.x-b.x+MOD)%MOD;
}
mint operator*(mint a, mint b) {
	return (a.x*b.x)%MOD;
}
mint operator/(mint a, mint b) {
	return (a.x*pot(b.x, MOD-2))%MOD;
}
const int LIM=207;
mint dp[LIM][LIM], T[2*LIM][LIM], sil[2*LIM];
int nxt[LIM][10], pre[LIM], post[LIM], odl[LIM], lpre, lpost, bylo[2*LIM][LIM];
vector<int>V[LIM];
mint c(ll n, ll k) {
	if(k>n) return 0;
	if(bylo[n][k]) return T[n][k];
	T[n][k]=sil[n];
	T[n][k]/=sil[n-k];
	T[n][k]/=sil[k];
	T[n][k]/=pot(2, n);
	bylo[n][k]=1;
	return T[n][k];
}
void DFS(int x, int o) {
	nxt[x][0]=o;
	++lpre;
	pre[x]=lpre;
	for(auto i : V[x]) if(i!=o) {
			odl[i]=odl[x]+1;
			DFS(i, x);
	}
	++lpost;
	post[x]=lpost;
}
bool oc(int a, int b) {
	return pre[a]<=pre[b] && post[a]>=post[b];
}
int lca(int a, int b) {
	if(oc(a, b)) return a;
	if(oc(b, a)) return b;
	for(int i=9; i>=0; --i) if(!oc(nxt[a][i], b)) a=nxt[a][i];
	return nxt[a][0];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	sil[0]=1;
	for(ll i=1; i<2*LIM; ++i) sil[i]=sil[i-1]*i;
	rep(i, LIM) rep(j, LIM) if(i+j>0) {
		for(int l=i; l<i+j; ++l) dp[i][j]+=c(i+j-1, l);
	}
	int n;
	cin >> n;
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	mint ans=0;
	rep(i, n) {
		mint akt=0;
		odl[i]=0;
		lpre=lpost=0;
		DFS(i, i);
		for(int j=1; j<10; ++j) {
			rep(l, n) {
				nxt[l][j]=nxt[nxt[l][j-1]][j-1];
			}
		}
		rep(j, n) for(int l=j+1; l<n; ++l) {
			int c=lca(j, l);
			akt+=dp[odl[l]-odl[c]][odl[j]-odl[c]];
		}
		ans+=akt;
	}
	ans/=n;
	cout << ans << '\n';
}