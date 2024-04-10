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

#define int ll

const int maxn = 5010;
const int iinf = 1<<29;
const ll inf = 1ll<<60;
const ll mod = 1e9+7;


void GG(){cout<<"-1\n"; exit(0);}

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

struct seg{
	int x0, y0, x1, y1;
	bool hor;
	seg(){
		cin>>x0>>y0>>x1>>y1;
		x0+=5002;
		y0+=5002;
		x1+=5002;
		y1+=5002;
		if (x0>x1) swap(x0,x1);
		if (y0>y1) swap(y0,y1);
		hor = (y0==y1);
	}
};

bool its(seg a, seg b){
	if (a.hor==b.hor) return 0;
	if (a.hor) swap(a,b); // a is vertical
	return (b.x0<=a.x0 && b.x1>=a.x1 && a.y0<=b.y0 && a.y1>=b.y1);
}

bool cmp (seg a, seg b){
	int aa = a.y1, bb = b.y1;
	if (aa!=bb) return aa>bb;
	return !a.hor;
}
	
vector<seg> v;
// bitset<maxn> bt [ maxn ];

const int MXN = maxn*2*2+1000;

int s[MXN];

void mo(int e, int v){
	e++;
	while (e<MXN){
		s[e]+=v;
		e+=e&(-e);
	}
}
ll qu (int e){
	e++;
	ll re = 0;
	while (e>0){
		re+=s[e];
		e-=e&(-e);
	}
	return re;
}

void cc(){
	REP(i,MXN){
		s[i]=0;
	}
}


main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n; cin>>n;
    REP(i,n){
    	seg tmp;
    	v.pb(tmp);
    }
    sort(ALL(v),cmp);
    ll re = 0;
    REP(i,n){
    	cc();
    	if (!v[i].hor)continue;
    	REP(j,i){
    		if (i==j) continue;
    		if (its(v[i],v[j])){
    			// cout<<i<<' '<<j<<'\n';
    			mo(v[j].x0,1);
    		}
    	}
    	RREP(j,i){
    		if (i==j) continue;
    		if (v[j].hor){
    			ll s = qu(v[j].x1)-qu(v[j].x0-1);
    			re += s * (s-1)/2;
    			// cout<<"tried..."<<endl;
    			// debug(qu(v[j].x1));
    			// cout<<v[j].x1<<' '<<v[j].x0<<endl;
    		}else{
    			if (its(v[i],v[j])) mo(v[j].x0,-1);
    		}
    	}
    }
    cout<<re<<'\n';
    
}