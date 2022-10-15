#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops")
#define ll long long 
#define pii pair<double, double>
#define ull unsigned ll
#define f first
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
#define sq(x) (x)*(x)
using namespace std;

// #define int ll

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

double dist(pii x){
	// debug(hypot(x.f, x.s));
	return hypot(x.f, x.s);
}

double PI = acos(-1);

main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, px, py; cin>>n>>px>>py;
    vector<pii> v(n); 
    REP(i,n){
    	cin>>v[i].f>>v[i].s; v[i].f-=px, v[i].s-=py;
    }
    double mx = 0, mn = 1e8;
    REP(i,n){
    	pii pa = v[i], pb = v[(i+1)%n];
    	pii a = {pb.f-pa.f, pb.s-pa.s};
    	pii b = {-pa.f, -pa.s};
    	double cross = a.f*b.s-a.s*b.f;
    	double dot = a.f*b.f+a.s*b.s;
    	cross/=dist(a);
    	cross = abs(cross);
    	if (dot>0 && dot < sq(dist(a)))MNTO(mn,  cross);
    	MNTO(mn,  dist(pa));
    	MXTO(mx, dist(pa));
    }
    // debug(mn); debug(mx);
    double c1 = sq(mx)*PI - sq(mn)*PI;
    cout<<fixed<<setprecision(11)<<c1<<endl;
    
}