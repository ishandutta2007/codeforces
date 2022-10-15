#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int, int>
#define ull unsigned ll
#define f first
#define s second
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for (int i=(n-1); i>=0; i--)
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define SQ(x) (x)*(x)
#define MN(a,b) a = min(a,(__typeof__(a))(b))
#define MX(a,b) a = max(a,(__typeof__(a))(b))
#define pb push_back
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#ifdef BALBIT
#define IOS()
#define bug(...) fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);_do(__VA_ARGS__);
template<typename T> void _do(T &&x){cerr<<x<<endl;}
template<typename T, typename ...S> void _do(T &&x, S &&...y){cerr<<x<<", ";_do(y...);}
#else
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define bug(...)
#endif

#define int ll

const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

ll mpow(ll a, ll n, ll mo = mod){ // a^n % mod
    ll re=1;
    while (n>0){
        if (n&1) re = re*a %mo;
        a = a*a %mo;
        n>>=1;
    }
    return re;
}

ll inv (ll b, ll mo = mod){
    if (b==1) return b;
    return (mo-mo/b) * inv(mo%b) % mo;
}

const int maxn = 1e5+5;

ll go(vector<int> a, int to){
	int n = SZ(a);
	int prv = -1;
	int need = 0;
	int mf = -1;
	int more = 0;
	ll re = 0;
	REP(i,n){
		a[i] %= to;
		if (more != 0){
			re += min(more, to-more); a[i] += more; a[i]%= to; more= 0;
		}
		if (a[i] !=0) {
			more = (more + a[i]) % to;
		}
	}
	bug(to, re);
	return re;
}

main(){
    IOS();
    int n; cin>>n;
    vector<int> a(n);
    ll s = 0; 
    REP(i,n){
    	cin>>a[i]; s += a[i];
    }
    int tg = sqrt(s)+1;
    ll re = inf;
    FOR(ty,2, tg){
    	if (s%ty == 0){
    		while (s%ty==0){
    			s/=ty;
    		}
    		MN(re,go(a,ty));
    	}
    }
    if (s!=1){
    	MN(re,go(a,s));
    }
    if (re == inf) cout<<-1<<endl;
    else cout<<re<<endl;
}