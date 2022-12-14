//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
// #define int ll
int in[N]; 
struct seg{
	#define U(x,y) (x+y)
	#define a0 0
	void toz(ll x){z=x,state=1;}
	void toa(){a=z*(r-l+1),z=0,state=0;}
	ll a,z; bool state;
	int l,r; seg *lc,*rc;
	void init(int,int);
	void up(){a=U(lc->a,rc->a);}
	void down(){
		if(!state)return;
		if(l<r){lc->toz(z); rc->toz(z);}
		toa();
	}
	void update(int x,int y,ll k){
		if(x>r || y<l){down(); return;}
		if(x<=l && y>=r){toz(k); down(); return;}
		down();
		lc->update(x,y,k);
		rc->update(x,y,k);
		up();
	}
	ll query(int x,int y){
		if(x>r || y<l)return a0;
		down();
		if(x<=l && y>=r)return a;
		return U(lc->query(x,y),rc->query(x,y));
	}
}tr[N*2],*pl;
void seg::init(int _l,int _r){
	l=_l,r=_r; state=0; z=0;
	if(l==r){a=in[l]; return;}
	int m=(l+r)>>1;
	lc=++pl; lc->init(l,m);
	rc=++pl; rc->init(m+1,r);
	up();
}
void init(int l,int r){
	pl=tr; tr->init(l,r);
}
char s1[N],s2[N];
pii op[N];
void Solve(){
	int n=read(),q=read();
	scanf("%s%s",s1,s2);
	repeat(i,0,n)
		in[i]=s2[i]=='1';
	repeat(i,0,q)op[i]={read()-1,read()-1};
	init(0,n-1);
	repeat_back(i,0,q){
		int l=op[i].fi,r=op[i].se,len=r-l+1;
		int cnt=tr->query(l,r);
		// orz(len,cnt);
		if(len%2==0 && cnt==len/2){
			puts("NO");
			return;
		}
		tr->update(l,r,cnt>len/2);
		// repeat(i,0,n)cout<<tr->query(i,i); cout<<endl;
	}
	repeat(i,0,n)
	if(tr->query(i,i)!=(s1[i]=='1')){
		puts("NO");
		return;
	}
	puts("YES");
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}