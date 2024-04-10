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
struct mat{
	static const int N=150;
	bitset<N> a[N];
	mat(){}
	mat(int n){
		repeat(i,0,n)a[i][i]=1;
	}
	friend mat mul(const mat &a,const mat &b,int n){
		mat ans;
		repeat(k,0,n)
		repeat(i,0,n)
		if(a[i][k])
			ans[i]|=b[k];
		return ans;
	}
	friend mat qpow(mat a,ll b,int n){
		mat ans(n);
		while(b){
			if(b&1)ans=mul(ans,a,n);
			a=mul(a,a,n); b>>=1;
		}
		return ans;
	}
	void print(int n){
		puts("mat=");
		repeat(i,0,n)
		repeat(j,0,n)
			::print(a[i][j],j==n-1);
	}
	bitset<N> &operator[](int x){return a[x];}
	const bitset<N> &operator[](int x)const{return a[x];}
};
typedef array<int,3> edge;
edge e[N];
mat A,eset;
void Solve(){
	int n=read(),m=read();
	repeat(i,0,m){
		int x=read()-1,y=read()-1,d=read();
		e[i]={x,y,d};
	}
	sort(e,e+m,[](edge a,edge b){
		return a[2]<b[2];
	});
	int step=0,ans=inf;
	A=mat(n);
	repeat(i,0,m){
		if(step<e[i][2]){
			A=mul(A,qpow(eset,e[i][2]-step,n),n);
		}
		step=e[i][2];
		eset[e[i][0]][e[i][1]]=1;
		vector<int> dis(n,inf);
		queue<int> q;
		repeat(i,0,n)if(A[0][i]){
			dis[i]=step;
			q.push(i);
		}
		while(!q.empty()){
			int x=q.front(); q.pop();
			repeat(p,0,n)if(eset[x][p] && dis[p]==inf){
				q.push(p);
				dis[p]=dis[x]+1;
			}
		}
		ans=min(ans,dis[n-1]);
	}
	if(ans==inf)puts("Impossible");
	else print(ans,1);
}
signed main(){
	// freopen("data.txt","r",stdin);
	int T=1; // T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}