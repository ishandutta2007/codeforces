#include <bits/stdc++.h>
using namespace std;
  
#define rng(i,a,b) for(int i=int(a);i<=int(b);i++)
#define rep(i,b) rng(i,0,b-1)
#define gnr(i,b,a) for(int i=int(b);i>=int(a);i--)
#define per(i,b) gnr(i,b-1,0)
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#define si(x) int(x.size())
template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
using ll=long long;
using ull=unsigned long long;
using pil=pair<int,ll>;
using pli=pair<ll,int>;
using pll=pair<ll,ll>;
using t3=tuple<int,int,int>;

struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	/*modular inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modular(x);
	}*/
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};
extern constexpr modinfo base{998244353,0};
using mint=modular<base>;
#define N_ 201000

vi G, SZ;
vc<vc<ll>>S, IT;
int w[N_];
vc<ll> Build(vc<ll> T){
	int s = 1;
	while(s < si(T))s<<=1;
	vc<ll> R(s*2);
	rep(i,si(T))R[s+i]=T[i];
	gnr(i,s-1,1)R[i]=max(R[i*2],R[i*2+1]);
	//printf("u %d\n",si(R)/2);
	return R;
}
void Add(int a, int x, int sz, ll d){
	x+=sz;
	IT[a][x]+=d;
	while(x!=1){
		x>>=1;
		IT[a][x]=max(IT[a][x*2],IT[a][x*2+1]);
	}
}
void Solve(){
	int n, Q;
	scanf("%d%d",&n,&Q);
	rep(i,n){
		scanf("%d",&w[i]);
	}
	G.clear();
	S.clear();
	SZ.clear();
	IT.clear();
	ll ans=0;
	rng(i,1,n-1){
		if(n%i==0){
			G.pb(i);
			vc<ll>T(i);
			rep(j,i){
				ll s=0;
				rep(k,n/i){
					//printf("%d %d\n",k*i+j,w[k*i+j]);
					s += w[k*i+j];
				}
				if(ans<s*i)ans=s*i;
				T[j]=s;
			}
			IT.pb(Build(T));
			SZ.pb(si(IT.back()) / 2);
			S.pb(T);
		}
	}
	printf("%lld\n",ans);
	while(Q--){
		int a, b;
		scanf("%d%d",&a,&b);
		a--;
		ll d = b-w[a];
		//printf("%lld\n",d);
		w[a] = b;

		ll r=0;
		rep(i,si(G)){
			//printf("!%d\n",SZ[i]);
			Add(i,a%G[i],SZ[i],d);
			r=max(r,IT[i][1] * G[i]);
		}
		printf("%lld\n",r);
	}
}

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		Solve();
	}
}