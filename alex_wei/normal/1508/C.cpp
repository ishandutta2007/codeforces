/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using pdd = pair <double,double>;
using vint = vector <int>;
using vpii = vector <pii>;

#define fi first
#define se second
#define pb push_back
#define mpi make_pair
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))
#define mcpy(x,y) memcpy(x,y,sizeof(y))

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void print(int x){
		if(x<0)return pc('-'),print(-x),void();
		if(x>9)print(x/10);
		pc(x%10+'0');
	}
}

namespace math{
	const int mod=99824353;
	const int maxn=2e6+5;

	ll ksm(ll a,ll b,ll p){
		ll s=1,m=a%p;
		while(b){
			if(b&1)s=s*m%p;
			m=m*m%p,b>>=1;
		} return s;
	} ll ksm(ll a,ll b){
		ll s=1,m=a%mod;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	} ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1;
		for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

using namespace IO;
//using namespace math;

const int N=2e5+5;
const int K=4e3+5;
const int inf=0x3f3f3f3f;

ll n,m,ept,ans,deg[N],xo,cnt=1;
bool buc[K][K];
map <pii,bool> mp;

int f[N];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
} void merge(int x,int y){
	int xx=find(x),yy=find(y);
	if(xx!=yy)cnt++,f[xx]=yy;
}

struct edge{
	int u,v,w;
	bool operator < (const edge &a) const {
		return w<a.w;
	}
}e[N];
vector <pii> ee[N];

int fa[N][18],ok[N][18],dep[N];
void dfs(int id,int f,int d){
	dep[id]=d;
	for(pii it:ee[id])
		if(it.fi!=f){
			ok[it.fi][0]=it.se;
			fa[it.fi][0]=id;
			dfs(it.fi,id,d+1);
		}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)f[i]=i;
	
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		mp[{e[i].u,e[i].v}]=mp[{e[i].v,e[i].u}]=1;
		deg[e[i].u]++,deg[e[i].v]++;
		xo^=e[i].w;
	} sort(e+1,e+m+1);
	
	if(n>=K){
		int B=sqrt(n);
		for(int i=1;i<=m;i++)
			if(deg[i]<=B){
				for(int j=1;j<=n;j++)
					if(!mp[{i,j}])merge(i,j);
					else for(int k=1;k<=n;k++)
						if(!mp[{j,k}])merge(j,k);
				break;
			}
		for(int i=1;i<=m&&cnt<n;i++){
			int x=e[i].u,y=e[i].v;
			if(find(x)!=find(y))ans+=e[i].w,merge(x,y); 
		} cout<<ans<<endl;
	} else{
		for(int i=1;i<=m;i++)
			buc[e[i].u][e[i].v]=buc[e[i].v][e[i].u]=1;
		bool ept=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(!buc[i][j]){
					if(find(i)!=find(j))merge(i,j),ee[i].pb({j,1}),ee[j].pb({i,1});
					else ept=1;
				}
		for(int i=1;i<=m&&cnt<n;i++){
			int x=e[i].u,y=e[i].v;
			if(find(x)!=find(y))
				ans+=e[i].w,merge(x,y),ee[e[i].u].pb({e[i].v,0}),ee[e[i].v].pb({e[i].u,0});
		}
		if(ept)cout<<ans<<endl;
		else{
			dfs(1,0,1),ans+=xo;
			for(int i=1;i<18;i++)
				for(int j=1;j<=n;j++)
					ok[i][j]=ok[i][j-1]|ok[fa[i][j-1]][j-1],
					fa[i][j]=fa[fa[i][j-1]][j-1];
			for(int i=1;i<=m;i++){
				int x=e[i].u,y=e[i].v,check=0;
				if(dep[x]<dep[y])swap(x,y);
				for(int i=17;~i;i--)
					if(dep[fa[x][i]]>=dep[y])
						check|=ok[x][i],x=fa[x][i];
				if(x!=y){
					for(int i=17;~i;i--)
						if(fa[x][i]!=fa[y][i])
							check|=ok[x][i]|ok[y][i],x=fa[x][i],y=fa[y][i];
					check|=ok[x][0]|ok[y][0];
				}
				if(check){
					ans=min(ans,ans-xo+e[i].w);
					break;
				}
			} cout<<ans<<endl;
		}
	}
	
	return 0;
}
/*
5 9
1 2 1000000000
2 5 1000000000
3 5 1000000000
1 3 10
1 5 15
2 3 1000000000
2 4 88
3 4 123
4 5 127
*/