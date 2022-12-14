#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
//#define endl "\n"
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=1000010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
int in[N];
struct seg{
	#define U(x,y) (x+y)
	#define a0 0
	void toz(ll x1,ll x2){
		z1^=x1,z2^=x2;
	}
	ll a,z1,z2; seg *lc,*rc;
	void init(int,int);
	void up(){a=U(lc->a,rc->a);}
	void down(int l,int r){
		if(z1&1)swap(lc,rc),z1^=3;
		if(z2&1)swap(lc,rc);
		if(l<r){
			lc->toz(z1>>1,z2>>1);
			rc->toz(z1>>1,z2>>1);
		}
		z1=z2=0;
	}
	void update(int l,int r,ll k1,ll k2){
		z1^=k1;
		z2^=k2;
		down(l,r);
	}
	void change(int l,int r,ll x,ll y){
		if(l==x && r==x){
			down(l,r);
			a=y;
			return;
		}
		if(x<l || x>r){down(l,r); return;}
		int m=(l+r)/2; down(l,r);
		lc->change(l,m,x,y);
		rc->change(m+1,r,x,y);
		up();
	}
	ll query(int l,int r,int x,int y){
		x=max(x,l); y=min(y,r); if(x>y)return a0;
		down(l,r);
		if(x==l && y==r)return a;
		int m=(l+r)/2;
		return U(lc->query(l,m,x,y),rc->query(m+1,r,x,y));
	}
}tr[N*2],*pl;
void seg::init(int l,int r){
	if(l==r){a=in[l]; return;}
	int m=(l+r)/2;
	lc=++pl; lc->init(l,m);
	rc=++pl; rc->init(m+1,r);
	up();
}
void init(int l,int r){
	pl=tr; tr->init(l,r);
}
void Solve(){
	int nn=read(),q=read(); int n=1<<nn;
	repeat(i,0,n)in[i]=read();
	init(0,n-1);
	while(q--){
		int op=read();
		if(op==1){
			int x=read()-1,y=read();
			tr->change(0,n-1,x,y);
		}
		else if(op==2){
			int x=read(); x=nn-x;
			tr->update(0,n-1,1<<x,0);
		}
		else if(op==3){
			int x=read(); x=max(0ll,(nn-x)-1);
			tr->update(0,n-1,0,1<<x);
		}
		else{
			int x=read()-1,y=read()-1;
			cout<<tr->query(0,n-1,x,y)<<endl;
		}
		//repeat(i,0,n)cerr<<tr->query(0,n-1,i,i)<<'-'; cerr<<endl;
		//cout<<tr->query(0,n-1,0,n-1)<<endl;
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	while(T--)Solve();
	return 0;
}