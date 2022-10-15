#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pic pair<int, char>
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
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

#define int ll

const int maxn = 1e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

ll pow(ll a, ll n){ // a^n % mod
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


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, m, k; cin>>n>>m>>k;
    queue<ll> a;
    REP(i,m) {
    	ll in; cin>>in; a.push(in);
    }
    ll bar = 0;
    int nop = 0;
    while (!a.empty()){
    	int nd = 0;
    	while (!a.empty() && ((a.front()-bar)<=k)){
    		// cout<<a.front();
    		a.pop(); nd ++;
    	}
    	// cout<<"NNN";
    	bar+=nd; if (nd) nop++;
    	if (!a.empty()){
    		int nxt = a.front();
    		bar+= k*((nxt-bar-1)/k);
    	}
    }
    cout<<nop<<endl;
    
}