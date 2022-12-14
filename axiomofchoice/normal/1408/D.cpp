#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=2010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<int,int> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
const int X=1000010;
int ans=inf;
struct seg{
	#define U(x,y) min(x,y)
	#define a0 inf
	void toz(int x){z=max(z,x);}
	int z;
	int l,r; seg *lc,*rc;
	void init(int,int);
	void down(){
		if(l<r){lc->toz(z); rc->toz(z);}
	}
	void update(int x,int y,ll k){
		if(x>r || y<l){return;}
		if(x<=l && y>=r){toz(k); down(); return;}
		down();
		lc->update(x,y,k);
		rc->update(x,y,k);
	}
	void dfs(){
		down();
		if(l<r)lc->dfs(),rc->dfs();
		else{
			//cout<<l<<' '<<z<<endl; pause;
			ans=min(ans,z+l);
		}
	}
}tr[X*2],*pl;
void seg::init(int _l,int _r){
	l=_l,r=_r;
	if(l==r){z=0; return;}
	int m=(l+r)>>1;
	lc=++pl; lc->init(l,m);
	rc=++pl; rc->init(m+1,r);
}
void init(int l,int r){
	pl=tr; tr->init(l,r);
}
#define x fi
#define y se
vector<pii> a,v,s;
int h[X];
void Solve(){
	init(0,X);
	int n=read(),m=read();
	repeat(i,0,n){
		int x=read(),y=read();
		a<<pii(x,y);
	}
	mst(h,-1);
	repeat(i,0,m){
		int x=read(),y=read();
		h[x]=max(h[x],y);
	}
	repeat_back(i,0,X-1)
		h[i]=max(h[i],h[i+1]);
	v.push_back({0,h[0]+1});
	repeat(i,0,X-1)
	if(h[i]!=h[i+1])
		v.push_back({i+1,h[i+1]+1});
	repeat(i,0,n){
		s.clear();
		repeat(j,0,v.size())
			s<<pii(max(-1,v[j].x-a[i].x),max(-1,v[j].y-a[i].y));
		
		//orzeach(s);
		repeat(j,0,s.size()-1)
		if(s[j+1].x>0){
			tr->update(max(s[j].x,0),s[j+1].x-1,s[j].y);
		}
	}
	tr->dfs();
	cout<<ans<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}