#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#pragma GCC optimize("Ofast", "unroll-loops")

#define ll long long 
#define int ll
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (ll i=(a); i<(b); i++)
#define REP(i,n) for (ll i=0; i<(n); i++)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define SQ(x) (x)*(x)
#define MNTO(a,b) a = min(a,(__typeof__(a))(b))
#define MXTO(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define debug(x) cerr<<#x<<" is "<<x<<endl
using namespace std;
using namespace __gnu_pbds; //required 


template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

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

map<int, vector<int> > aty;
map<int, int> numof;

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // ordered_set<pii> pt;
    ordered_set<int> pts;
    int n; cin>>n;
    vector<int> yc; 
    // set<int> tmpst;
    REP(i,n){
    	int x, y; cin>>x>>y;
    	// tmpst.insert(x);
    	pts.insert(x);
    	numof[x]++;
    	aty[y].pb(x);
    	yc.pb(y);
    }
    sort(ALL(yc));
	yc.erase( unique( yc.begin(), yc.end() ), yc.end() );
	// cout<<"OK"<<endl;
	int XX = pts.size();
	int re = XX*(XX+1)/2;
	// debug(re);
	REP(i, SZ(yc)){
		int hi = yc[i]; 
		vector<int> elim = aty[hi];
		sort(ALL(elim));
		vector<int> ps;
		vector<int> atme(SZ(elim));
		REP(j, SZ(elim)){
			ps.pb(pts.order_of_key(elim[j])); 
			// debug(atme[i]);
			numof[elim[j]]--; if (numof[elim[j]]==0) pts.erase(elim[j]); else atme[j]++;
		}
		ps.pb(pts.size());

		ll rem  = 0;
		REP(j,SZ(ps)){
			if (j==0){
				rem += ps[j] * (ps[j]+1) /2;
			}else{
				int tmp = ps[j] - ps[j-1] -atme[j-1];
				rem += tmp * (tmp+1) /2;
			}
		}
		// debug(rem);
		re -= rem;
		re += ((ll)pts.size() * ((ll)pts.size()+1) /2 );
	}
    cout<<re<<endl;
}