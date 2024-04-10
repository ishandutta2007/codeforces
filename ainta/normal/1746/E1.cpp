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
#define N_ 101000

int n;
int V[N_], VU[N_];
void Guess(int a){
	printf("! %d\n",a);
	fflush(stdout);
	char p[20];
	scanf("%s",p);
	if(p[1]==')'){
		exit(0);
	}
}
int Query(vi &T){
	printf("? %d",si(T));
	for(auto &x: T)printf(" %d",x);
	puts("");
	fflush(stdout);
	char p[20];
	scanf("%s",p);
	if(p[0]=='Y')return 1;
	return 0;
}
int main(){
	scanf("%d",&n);
	vi T, F;
	rng(i,1,n){
		T.pb(i);
		F.pb(i);
	}
	int cnt = 0;
	while(1){
		rng(i,1,n){
			V[i]=0;
			VU[i]=0;
		}
		for(auto &x : T)V[x]|=1;
		for(auto &x : F)V[x]|=2;
		vi R;
		rng(i,1,n){
			//printf("%d ",V[i]);
			if(V[i])R.pb(i);
		}
		//puts("");
		//printf("%d\n",si(R));
		if(si(R)<=2){
			for(auto &x: R){
				Guess(x);
			}
			return 0;
		}

		if(si(R) == 3){
			rep(i,6){
				vi U;
				U.pb(R[i/2]);

				if(Query(U)){
					Guess(R[i/2]);
					int pv = i/2;
					vi P;
					P.pb(R[(pv+1)%3]);
					if(Query(P)){
						Guess(R[(pv+1)%3]);
					}
					else{
						Guess(R[(pv+2)%3]);
					}
				}
			}
			return 0;
		}
		vi Z[3];
		rng(i,1,n){
			if(V[i]){
				Z[V[i]-1].pb(i);
			}
		}
		int C[3];
		C[0] = si(Z[0])/2;
		C[1] = si(Z[1])/2;
		C[2] = (si(Z[2]) + 1)/2;
		vi U;
		cnt++;
		std::random_device randDev;
		std::mt19937 mtGenerator(randDev());
		std::shuffle(all(R), mtGenerator);

		rep(i,si(R)/2){
			U.pb(R[i]);
		}
		//printf("%d %d %d\n",C[0],C[1],C[2]);
/*		rep(i,3){
			rep(j,C[i]){
				U.pb(Z[i][j]);
			}
		}*/

		for(auto &x: U)VU[x]=1;
		vi NT, NF;
		if(Query(U)){
			for(auto &t: R){
				if(VU[t])NT.pb(t);
			}
			for(auto &t: T){
				if(!VU[t])NF.pb(t);
			}
		}
		else{
			for(auto &t: R){
				if(!VU[t])NT.pb(t);
			}
			for(auto &t: T){
				if(VU[t])NF.pb(t);
			}
		}
		T = NT;
		F = NF;
	}
}