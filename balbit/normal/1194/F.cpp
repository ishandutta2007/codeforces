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
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

// #define int ll

const int maxn = 2e5+5;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"No\n"; exit(0);}

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

ll fac[maxn];

void build(){
	fac[0]=1;
	FOR(i,1,maxn){
		fac[i]=fac[i-1]*i%mod;
	}
}

ll C(ll a, ll b){
	return fac[a] * inv(fac[a-b]) %mod* inv(fac[b])%mod;
}

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    build();
    int n; ll t; cin>>n>>t;
    vector<ll> a(n);
    REP(i,n) cin>>a[i];
    ll nx = 0; 
    ll p2 = 1;
    ll x = 0;
    ll re = 0;
    ll sum = 0;
    REP(i,n){
    	p2=p2*2%mod;
    	sum+=a[i];
    	if (sum>t) break;
    	if (sum+i+1>t){
    		if (nx==0) nx = p2, x = i+2;
    		else{ 
    			nx = (mod+nx*2 - C(i,x-1))%mod;
    		} 	
    		while (sum+x>1+t){ 
    			nx = (mod + nx - C(i+1,x-1) )%mod;
    			// cout<<"Rid C "<<i+1<<' '<<x-1<<'\n';
    			// cout<<C(i+1,x-1)<<'\n';
    			x--;
    		}
    		// debug(nx);
    		re+=nx*inv(p2)%mod;
    		re%=mod;
    		// cout<<nx<<"/"<<p2<<endl;
    	}else{
    		re++; re%=mod;
    		// cout<<1<<endl;
    	}
    }
    cout<<re<<'\n';
    
}