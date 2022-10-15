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

bool cmp(pii a, pii b){
	if (a.f!=b.f) return a.f<b.f;
	 return a.s>b.s;
}

int at[21][maxn];
// int rb[500000+5];

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q; cin>>n>>q;
    vector<pii> tmp;
    REP(i,n){
    	int a, b; cin>>a>>b;
    	tmp.pb({a,b});
    }
    sort(ALL(tmp),cmp);
    int mx = -1;
    vector<pii> v;
    REP(i,n){
    	if (tmp[i].s>mx){
    		mx = tmp[i].s;
    		v.pb(tmp[i]);
    		// cout<<tmp[i].f<<'-'<<tmp[i].s<<endl;
    		// rb[tmp[i].f]=tmp[i].s;
    	}
    }
    // v.pb({mx,iinf});
    int m = v.size();
    REP(i,21) REP(j,maxn){
    	at[i][j]=-1;
    }
    sort(ALL(v), cmp);
    REP(i,m){
    	// if (v[i].s>v.back().f) break;
    	at[0][i]=prev(upper_bound(ALL(v),make_pair(v[i].s,-1),cmp))-v.begin();
    	if (at[0][i]==i) at[0][i]=-1;
    	// debug(at[0][i]);
    }
    FOR(j,1,21) {
    	REP(i,m){
    		int f1 = at[j-1][i];
    		if (f1==-1) at[j][i]=-1;
    		else at[j][i]=at[j-1][f1];
    	}
    }
    while (q--){
    	int l, r; cin>>l>>r;
    	if (l<v[0].f) {cout<<-1<<'\n'; continue;}
    	int a = prev(upper_bound(ALL(v),make_pair(l,-1),cmp))-v.begin();
    	int tj = 1;
    	RREP(j,20){
    		// if (a==-1) cout<<-1<<'\n';
    		if (at[j][a]!=-1 && v[at[j][a]].s<r){
    			tj+=(1<<j);
    			a = at[j][a];
    		}
    		
    	}
    	// cout<<a<<": ";
    	if (v[a].s>=r) cout<<tj<<'\n';
    	else{
    		a = at[0][a];
    		if(a==-1) cout<<-1<<'\n';
    		else cout<<tj+1<<'\n';
    	}
    }
}