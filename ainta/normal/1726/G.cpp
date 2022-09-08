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
int w[N_], P[N_];
struct point{
    int a, ck, c;
};

void Solve(){
    int n;
    scanf("%d",&n);
    rng(i,1,n){
        scanf("%d",&w[i]);
    }
    map<pii,int>Map;
    rng(i,1,n){
        scanf("%d",&P[i]);
        Map[{w[i],P[i]}]+=1;
    }
    vc<point>V;
    for(auto [xx, c] : Map){
        V.pb({xx.fi,xx.se,c});
    }
    if(V[0].a == V.back().a){
        mint res=1;
        rng(i,1,n)res*=i;
        printf("%d\n",res.v);
        return;
    }
    int M = V[0].a + n-1;
    int Mx = V.back().a;
    if(Mx > M){
        puts("0");
        return;
    }
    for(auto &t: V){
        if(t.ck == 1 && t.a != M && t.c > 1){
            puts("0");
            return;
        }
    }
    int s = 0;
    mint res = 1;
    for(auto &t: V){
        if(t.a==M && t.ck==1){
            rep(i,t.c)res*=n-i;
            continue;
        }

        int u = M - t.a;
        if(t.ck == 0){
            if(s < u){
                puts("0");
                return;
            }
            rng(i,1,t.c)res*=i;
        }
        if(t.ck == 1){
            if(n - 1 - s > u){
                puts("0");
                return;
            }
        }

        s += t.c;
    }
    printf("%d\n",res.v);
}

int main(){
    int TC = 1;
    while(TC--){
        Solve();
    }
}