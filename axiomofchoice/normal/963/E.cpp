// #pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)!=1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)!=1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> vector<T> &operator<<(vector<T> &a,T b){a.push_back(b); return a;} template<typename T> T sqr(T x){return x*x;} void print(ll x,bool e=0){printf("%lld%c",x," \n"[e]);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
// #define int ll
struct vtr:vector<ll>{
	int l,r;
	void init(int _l,int _r){l=_l; r=_r; assign(r-l+1,0);}
	ll &operator[](int x){
		return at(x-l);
	}
};
int A[1010][1010];
struct mat{
	static const int N=200010;
	vtr a[N]; ll b[N]; int d,r,n;
	ll det;
	void r_div(int x,ll k){ // a[x][]/=k
		ll r=qpow(k,mod-2);
		for(auto &i:a[x])
			i=i*r%mod;
		b[x]=b[x]*r%mod;
		det=det*k%mod;
	}
	void r_plus(int x,int y,ll k){ // a[x][]+=a[y][]*k
		repeat(i,max(a[x].l,a[y].l),min(a[x].r,a[y].r)+1)
			(a[x][i]+=a[y][i]*k)%=mod;
		(b[x]+=b[y]*k)%=mod;
	}
	void r_swap(int x,int y){
		repeat(i,max(a[x].l,a[y].l),min(a[x].r,a[y].r)+1)
			swap(a[x][i],a[y][i]);
		swap(b[x],b[y]);
		det=-det;
	}
	void init(int n,int _d,int _r){
		d=_d; r=_r;
		repeat(i,0,n)a[i].init(i-d,i+r+d),b[i]=0;
	}
	bool gauss(int n){ // m is arbitrary, return whether succuss
		this->n=n; det=1;
		repeat(i,0,n){
			int t=-1;
			repeat(j,i,min(i+d+1,n))
				if(a[j][i]){t=j; break;}
			if(t==-1){det=0; return 0;}
			if(t!=i)r_swap(i,t);
			r_div(i,a[i][i]);
			repeat(j,i+1,min(i+d+1,n))
				if(a[j][i])r_plus(j,i,-a[j][i]);
		}
		repeat_back(i,0,n){
			repeat(j,max(0,i-d-r),i)
				if(a[j][i])r_plus(j,i,-a[j][i]);
		}
		return 1;
	}
	// ll get_det(int n){gauss(n); return det;} // return det
	vtr &operator[](int x){return a[x];}
	const vtr &operator[](int x)const{return a[x];}
	void print(){
		cout<<"print:"<<endl;
		repeat(i,0,n){
			repeat(j,max(0,a[i].l),min(n,a[i].r+1))
				A[i][j]=a[i][j];
			repeat(j,0,n)::print(A[i][j]);
			::print(b[i],1);
		}
		cout<<"endprint"<<endl;
	}
}a;
int r;
int f(int x,int y){
	return (x+r)*(2*r+1)+y+r;
}
void Solve(){
	r=read(); ll p1=read(),p2=read(),p3=read(),p4=read();
	int d=qpow(p1+p2+p3+p4,mod-2);
	(p1*=d)%=mod; (p2*=d)%=mod; (p3*=d)%=mod; (p4*=d)%=mod;
	int n=sqr(2*r+1);
	a.init(n,2*r+1,2*r+1);
	repeat(x,-r,r+1)
	repeat(y,-r,r+1)
	if(x*x+y*y>r*r){
		a[f(x,y)][f(x,y)]=1;
	}
	else{
		a[f(x,y)][f(x,y)]=1;
		if(x!=-r)a[f(x,y)][f(x-1,y)]=-p1;
		if(x!=+r)a[f(x,y)][f(x+1,y)]=-p3;
		if(y!=-r)a[f(x,y)][f(x,y-1)]=-p2;
		if(y!=+r)a[f(x,y)][f(x,y+1)]=-p4;
		a.b[f(x,y)]=1;
	}
	a.gauss(n);
	print((a.b[f(0,0)]+mod)%mod,1);
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; // T=read();
	repeat(ca,1,T+1){
		try{
			Solve();
		}
		catch(exception &e){
			cout<<e.what()<<endl;
			exit(0);
		} 
	}
	return 0;
}