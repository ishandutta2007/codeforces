/*
	Powered by C++11.
	Author : Alex_Wei.
*/

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
#define pb emplace_back
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

const int N=150+5;
const int inf=0x3f3f3f3f;

int n,m,d[N],dis=inf;
struct mat{
	bitset <N> a[N];
	void clear(){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				a[i][j]=0;
	} friend mat operator * (mat x,mat y){
		mat z; z.clear();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(x.a[i][j])
					z.a[i]|=y.a[j];
		return z;
	}
}base,ans;

struct edge{
	int u,v,w;
	bool operator < (const edge &x){
		return w<x.w;
	}
}e[N];

void ksm(mat &s,mat a,int b){
	while(b){
		if(b&1)s=s*a;
		a=a*a,b>>=1;
	}
}

bool vis[N];
int bfs(mat a){
	queue <pii> q; mem(vis,0);
	for(int i=0;i<n;i++)if(a.a[0][i])q.push({i,0}),vis[i]=1;
	while(!q.empty()){
		pii t=q.front(); q.pop();
		if(t.fi==n-1)return t.se;
		for(int i=0;i<n;i++)
			if(base.a[t.fi][i]&&!vis[i])
				q.push({i,t.se+1}),vis[i]=1;
	} return -1;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
	sort(e+1,e+m+1),ans.a[0][0]=1;
	if(e[1].w)cout<<"Impossible\n",exit(0);
	int step=0;
	for(int i=1;i<=m;i++){
		base.a[e[i].u-1][e[i].v-1]=1;
		int s=bfs(ans);
		if(s>=0)dis=min(dis,s+step);
		if(i<m)ksm(ans,base,e[i+1].w-e[i].w),step=e[i+1].w;
	} if(dis==inf)cout<<"Impossible\n";
	else cout<<dis<<endl;
	return 0;
}