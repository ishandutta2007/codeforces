#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;
 
void GG(){cout<<"No\n"; exit(0);}
 
 const int maxn = 1e6+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;
 
ll mpow(ll a, ll n){ // a^n % mod
	ll re=1;
	while (n>0){
		if (n&1) re = re*a %mod;
		a = a*a %mod;
		n>>=1;
	}
	return re;
}
 
ll inv (ll b){
	if (b==1) return b;
	return (mod-mod/b) * inv(mod%b) % mod;
}
 

// #define int ll
 
unordered_map<ull, int> mp;
const int B = 59;
ull pB[maxn];
 
main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m; cin>>n>>m;
    pB[0]=1;
    FOR(i,1,n){
    	pB[i]=pB[i-1]*B;
    }
    vector<vector<int>> g(n);
    REP(i,m){
    	int a, b; cin>>a>>b;
    	a--; b--;
    	g[a].pb(b); g[b].pb(a);
    }
    ll re = 0;
    REP(i,n){
    	ull bs = pB[i];
    	for (int &v : g[i]){
    		bs+=pB[v];
    	}
    	re+=mp[bs]; mp[bs]++;
    }
    mp.clear();
    REP(i,n){
    	ull bs = 0;
    	for (int &v : g[i]){
    		bs+=pB[v];
    	}
    	re+=mp[bs]; mp[bs]++;
    }
    cout<<re<<'\n';
    
}