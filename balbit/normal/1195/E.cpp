#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
// #define int ll
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
 

 
const int maxn = 3005;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
 ll mod = 1e9+7;
 
 
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
 
int md[maxn][maxn];
int g[maxn][maxn];
 
int n, m, a, b;

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    srand(time(NULL));
    cin>>n>>m;
    cin>>a>>b;
    int g0, x, y, z; cin>>g0>>x>>y>>z;
    ll nat = g0;
    vector <int> has;
    REP(i,n) REP(j,m){
    	g[i][j]=nat; 
    	// cout<<g[i][j]<<" \n"[j==m-1];
    	has.pb(nat);
    	nat =( nat*x+y)%z;
    }
    deque<pii> dd;
   	REP(i,n) {
   		dd.clear();
   		REP(j,m){
	   		
	   		if (SZ(dd) && j - dd.back().s >= b){
	   			dd.pop_back();
	   		}
	   		while (SZ(dd) && dd.front().f >= g[i][j]){
	   			dd.pop_front();
	   		}
	   		dd.push_front({g[i][j],j});
	   		if (j>=b-1){
	   			md[i][j]=dd.back().f;
	   			// debug(md[i][j]);
	   		}
   		}
   	}
   	ll re = 0;
   	int tt = 0;
   	// deque<pii> dd;
   	FOR(j,b-1,m) {
   		dd.clear();
   		FOR(i,0,n){
	   		
	   		if (SZ(dd) && i - dd.back().s >= a){
	   			dd.pop_back();
	   			// cout<<"REM"<<endl;
	   		}
	   		while (SZ(dd) && dd.front().f >= md[i][j]){
	   			// cout<<"RID"<<endl;
	   			dd.pop_front();
	   		}
	   		dd.push_front({md[i][j],i});
	   		if (i>=a-1){
	   			re+=dd.back().f;
	   			// debug(dd.back().f);
	   			tt++;
	   		}
   		}	
   	}
 	// debug(tt);
    cout<<re<<endl;
}