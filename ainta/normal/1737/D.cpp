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
extern constexpr modinfo base{998244353,0};
using mint=modular<base>;

ll rand_int(ll l, ll r) { //[l, r]
	#ifdef LOCAL
	static mt19937_64 gen;
	#else
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    #endif
    return uniform_int_distribution<ll>(l, r)(gen);
}
#define N_ 101000
char p[N_];

ll D[510][510];
int C[510][510];

int main(){
	int TC;
	scanf("%d",&TC);
	while(TC--){
		vc<t3>E;
		int n,m;
		scanf("%d%d",&n,&m);
		rng(i,1,n){
			rng(j,1,n){
				C[i][j]=1e9,D[i][j]=1e18;
			}
			C[i][i]=D[i][i]=0;
		}
		rep(i,m){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			E.pb({a,b,c});

			D[a][b]=min(D[a][b],(ll)c);
			D[b][a]=min(D[b][a],(ll)c);
			C[a][b]=C[b][a]=1;
		}
		rng(k,1,n){
			rng(i,1,n){
				rng(j,1,n){
					D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
					C[i][j]=min(C[i][j],C[i][k]+C[k][j]);
				}
			}
		}
		ll res = D[1][n];
		for(auto [a,b,c]:E){
			//printf("%d %lld %lld\n",)
			int d = min(C[1][a]+C[b][n]+1, C[1][b]+C[a][n]+1);
			rng(x,1,n){
				int t = min(C[x][a],C[x][b])+1;
				d = min(d,1+t+C[x][1]+C[x][n]);
				d = min(d,1+C[1][n]+min(C[x][1],C[x][n])+t);
			}
			res=min(res,1ll*d*c);
		}
		printf("%lld\n",res);
	}
}