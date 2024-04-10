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
#define N_ 101000
#define M_ 501000

mint F[M_+10], invF[M_+10];

int w[N_], B[N_], E[N_];
ll S[N_];

void init(){
    F[0]=1;
    rng(i,1,M_)F[i]=F[i-1]*i;
    invF[M_]=1;invF[M_]/=F[M_];
    gnr(i,M_,1)invF[i-1]=invF[i]*i;
}
mint Comb(int a, int b){
    return F[a]*invF[b]*invF[a-b];
}
void Solve(){
    int n;
    scanf("%d",&n);
    rng(i,1,n){
        scanf("%d",&w[i]);
        S[i]=S[i-1]+w[i];
    }
    int p1 = n, p2 = n;
    rng(i,1,n){
        while(p1>1 && S[n] - S[p1-1] <= S[i])p1--;
        while(p2>=1 && S[n] - S[p2-1] < S[i])p2--;
        B[i] = p1, E[i]=p2-1;
    }
    map<pii,int>BB, EE;
    rng(i,1,n-1){
        if(B[i]<=E[i]){
            if(!BB.count(pii(B[i],E[i]))){
                BB[{B[i],E[i]}] = i;
            }
            EE[{B[i],E[i]}] = i;
        }
    }
    mint res = 1;
    for(auto [t, b] : BB){
        auto [b2,e2] = t;
        int e = EE[{b2,e2}];
        if(b>e2)continue;
        if(e < b2){
            int l = e-b+1;
            int l2 = e2-b2+1;
            mint z = 0;
            rng(j,0,min(l,l2)){
                z+= Comb(l,j)*Comb(l2,j);
            }
            res *= z;

        }
        else{
            int l = e-b+1;
            rng(j,1,l)res *= 2;
        }
    }
    printf("%d\n",res.v);
}

int main(){
    init();
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}