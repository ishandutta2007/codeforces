#include <bits/stdc++.h>
using namespace std; //using namespace rel_ops;
#define lll __int128
typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2;
typedef double lf; typedef long double llf; const lf err=1e-11; const lf pi=acos(-1);
typedef pair<int,int> pii;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define qwq (cerr<<"qwq"<<endl)
#define orz(x) (cerr<<#x": "<<x<<endl)
#define orzarr(a,n) {cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}
#define orzeach(a) {cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}
#define fi first
#define se second
inline ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;}
inline lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;}
//inline auto sqr(const auto &x){return x*x;}
//ostream &operator<<(ostream &o,const pair<auto,auto> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
mt19937 rnd(time(0));
const int N=1000010;
const int mod=(1?1000000007:998244353);
#define int ll
ll in[N];
struct seg{ //init(1,n)tr->sth()
	#define U(x,y) max(x,y) //
	#define a0 -INF //
	void toz(ll x){z+=x,state=1;} //
	void toa(){a+=z,state=0,z=0;} //
	ll a,z; bool state; //
	int l,r;
	seg *lc,*rc;
	void init(int,int);
	void up(){
		a=U(lc->a,rc->a);
	}
	void down(){
		if(!state)return;
		if(l<r){
			lc->toz(z);
			rc->toz(z);
		}
		toa();
	}
	void update(int x,int y,ll k){
		x=max(x,l); y=min(y,r); if(x>y){down();return;}
		if(x==l && y==r){
			toz(k);
			down();
			return;
		}
		down();
		lc->update(x,y,k);
		rc->update(x,y,k);
		up();
	}
	ll query(int x,int y){
		x=max(x,l); y=min(y,r); if(x>y)return a0;
		down();
		if(x==l && y==r)
			return a;
		return U(lc->query(x,y),rc->query(x,y));
	}
}tr[N*2],*pl;
void seg::init(int _l,int _r){
	l=_l,r=_r;
	state=0;
	if(l==r){
		a=in[l];
		return;
	}
	int m=(l+r)>>1;
	lc=++pl; lc->init(l,m);
	rc=++pl; rc->init(m+1,r);
	up();
}
void init(int l,int r){
	pl=tr;
	tr->init(l,r);
}
struct X{
	ll x,y,cls,cost;
	bool operator<(X b)const{
		return make_pair(x,cls)<make_pair(b.x,b.cls);
	}
};
vector<X> x;
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n=read(),m=read(),p=read();
	while(n--){
		ll xx=read(),cost=read();
		x.push_back({xx,0,1,cost});
	}
	fill(in,in+N,-INF);
	while(m--){
		ll yy=read(),cost=read();
		in[yy]=max(in[yy],-cost);
	}
	while(p--){
		ll xx=read(),yy=read(),cost=read();
		x.push_back({xx,yy,2,cost});
	}
	init(1,1000000);
	sort(x.begin(),x.end());
	ll ans=-INF;
	for(auto i:x){
		if(i.cls==1){
			ll now=tr->query(1,1000000);
			ans=max(ans,now-i.cost);
			//orz("que "<<now<<' '<<i.cost);
		}
		else{
			tr->update(i.y+1,1000000,i.cost);
			//orz("upd "<<i.y+1<<' '<<i.cost);
		}
		//repeat(i,0,7)
			//cout<<i<<' '<<tr->query(i,i)<<endl;
	}
	cout<<ans<<endl;
	return 0;
}