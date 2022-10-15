#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
// #define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;

#define int ll

const int maxn = 1e3+5;
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

int f[maxn][10005];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    REP(i,maxn) REP(j,10005)f[i][j]=-inf;

    int n, W, B, X; cin>>n>>W>>B>>X;
    f[0][0] = W; // 1 - indexed
    // Starting at -1, taken 0 birds
    vector<int> c(n+1), cost(n+1); 
    FOR(i,1,n+1) cin>>c[i];
    FOR(i,1,n+1) cin>>cost[i];
    int re = 0;
    FOR(at,1, n+1){
    	REP(took, 1e4+1){
    		int MX = W + took*B;
    		REP(take,c[at]+1){
	    		if (took-take<0) break;
	    		int prv = f[at-1][took-take]+X;
	    		MNTO(prv, W + B* (took-take)); // Previous Bound
	    		if (prv>=cost[at]*take){
	    			MXTO(f[at][took], prv - cost[at]*take);
	    			MNTO(f[at][took],MX);
	    			MX+=B;
	    			MXTO(re, took);
	    		}
    		}
    	}
    }
    cout<<re<<endl;
}