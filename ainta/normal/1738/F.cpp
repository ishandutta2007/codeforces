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

int Deg[1010], vis[1010];
vi E[1010];

void addE(int a, int b){
    E[a].pb(b);
    E[b].pb(a);
}
int cnt;
void DFS(int a){
    vis[a]=cnt;
    for(auto &t : E[a]){
        if(!vis[t])DFS(t);
    }
}

void Solve(){
    int n;
    scanf("%d",&n);
    rng(i,1,n){
        E[i].clear();
        vis[i]=0;
    }
    rng(i,1,n){
        scanf("%d",&Deg[i]);
    }
    while(1){
        int Mx = -1, x = -1;
        rng(i,1,n){
            if(!vis[i] && Mx < Deg[i]){
                x = i;
                Mx = Deg[i];
            }
        }
        if(x==-1)break;
        vis[x] = 1;
        rng(i,1,Deg[x]){
            printf("? %d\n",x);
            fflush(stdout);
            int a;
            scanf("%d",&a);
            addE(a,x);
            if(vis[a])break;
            vis[a]=1;
        }
    }
    rng(i,1,n)vis[i]=0;
    cnt = 0;
    rng(i,1,n){
        if(!vis[i]){
            cnt++;
            DFS(i);
        }
    }
    printf("!");
    rng(i,1,n)printf(" %d",vis[i]);
    puts("");
    fflush(stdout);
}

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        Solve();
    }
}