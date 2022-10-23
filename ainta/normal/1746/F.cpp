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
using ll=long long;
using pii=pair<int,int>;
using vi=vc<int>;
using uint=unsigned;
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
extern constexpr modinfo base{1000000007,0};
using mint=modular<base>;
 
ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}
#define M_ (1<<20)
#define N_ 301000

int n, Q;
int w[N_], Bad[N_];
struct QQ{
	int ck,a,b,c;
};
vc<QQ>U;
int P[N_], BIT[N_];
void Add(int a, int b){
	while(a<N_){
		BIT[a]+=b;
		a+=(a&-a);
	}
}
int Sum(int a){
	int r=0;
	while(a){
		r+=BIT[a];
		a-=(a&-a);
	}
	return r;
}
void Do(vi &Z){
	rep(i,N_)BIT[i]=0;
	rng(i,1,n){
		P[i] = Z[w[i]-1];
		Add(i,P[i]);
	}
	rep(i,Q){
		auto [ck,a,b,c] = U[i];
		if(ck==1){
			Add(a,-P[a]);
			P[a] = Z[b-1];
			Add(a,P[a]);
			continue;
		}
		if((b-(a-1))%c){
			Bad[i] = 1;
		}
		//printf("%d %d %d\n",a,b,Sum(b) - Sum(a-1));
		if((Sum(b) - Sum(a-1))%c){
			Bad[i] = 1;
		}
	}
}
int main(){
	scanf("%d%d",&n,&Q);
	map<int,int>Map;
	rng(i,1,n){
		scanf("%d",&w[i]);
		Map[w[i]]=1;
	}
	rep(i,Q){
		int ck,a,b,c =0;
		scanf("%d%d%d",&ck,&a,&b);
		if(ck==2)scanf("%d",&c);
		else Map[b]=1;
		U.pb({ck,a,b,c});
	}
	map<int,int>Num;
	int cnt = 0;
	for(auto [a,b] : Map){
		Num[a] = ++cnt;
	}
	rng(i,1,n){
		w[i] = Num[w[i]];
	}
	rep(i,Q){
		if(U[i].ck==1){
			U[i].b = Num[U[i].b];
		}
	}

	std::random_device randDev;
	std::mt19937 mtGenerator(randDev());
	vi Z(cnt);
	rep(i,cnt/2){
		Z[i] = 1;
	}
	int TC = 40;
	rep(TT,TC){
		shuffle(all(Z), mtGenerator);
		Do(Z);
	}
	rep(i,Q){
		if(U[i].ck==1)continue;
		if(Bad[i])puts("NO");
		else puts("YES");
	}
}