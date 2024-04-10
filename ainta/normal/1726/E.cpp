#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
 
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
using ull=unsigned ll;
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

#define N_ 301000

mint D[N_], F[N_], invF[N_], U[N_];
void init(){
    F[0]=1;
    rep(i,N_-1)F[i+1]=F[i] * (i+1);
    invF[N_ - 1] = 1;
    invF[N_ - 1] /= F[N_ - 1];
    gnr(i,N_-1, 1)invF[i-1] = invF[i]*i;
}
mint Comb(int a, int b){
    return F[a]*invF[b]*invF[a-b];
}
int Get(int n){

    vi Z(n);
    rep(i,n)Z[i]=i;
    int s=0;
    do{
        vi Y(si(Z));
        rep(i,si(Z))Y[Z[i]]=i;
        int ck=1;
        rep(i,si(Z)){
            if(abs(Z[i]-Y[i])>1)ck=0;
        }
        if(ck){
            //for(auto &t: Z)printf("%d ",t);
            //puts("");
        }
        s+=ck;
    }while(next_permutation(all(Z)));
    return s;
}
void Solve(){
    int n;
    scanf("%d",&n);
    D[0]=1;
    rng(i,1,n){
        D[i] = D[i-1];
        if(i>=2) D[i] += D[i-2] * (i-1);
    }
    mint tp = 1;
    mint res= 0;
    U[0]=1;
    rng(i,1,n){
        U[i]=U[i-1]*(2*i-1);
    }
    rng(i,0,n/4){
        res += D[n-4*i] * tp * Comb(n-2*i, 2*i) * U[i];
        tp *= 2;
    }
    printf("%d\n",res.v);
    //printf("%d\n",Get(n));
}

int main(){
    int TC;
    init();
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}