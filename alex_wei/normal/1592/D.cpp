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
	const int mod=998244353;
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

const int N=1e3+5;
const int inf=0x3f3f3f3f;

int n,mx;
vector <int> e[N];
bool mp[N][N],tg[N][N];
int query(vint q){
	cout<<"? ";
	cout<<q.size()<<" ";
	for(int it:q)cout<<it<<" ";
	cout<<endl;
	int res; cin>>res;
	return res;
}
void ans(int x,int y){
	cout<<"! "<<x<<' '<<y<<endl;
	exit(0);
}

int lim;
vpii cur;
void dfs(int id,int f){
	if(cur.size()>=lim)return;
	for(int it:e[id]){
		if(it==f)continue;
		if(tg[id][it]||!mp[id][it])continue;
		tg[id][it]=tg[it][id]=1;
		cur.pb(id,it),dfs(it,id);
		if(cur.size()>=lim)return;
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v; cin>>u>>v;
		e[u].pb(v),e[v].pb(u),mp[u][v]=mp[v][u]=1;
	}
	vint ori;
	for(int i=1;i<=n;i++)ori.pb(i);
	mx=query(ori);
	
	int sz=n-1;
	while(sz>1){
		lim=sz>>1,cur.clear(),mem(tg,0);
		for(int i=1;i<=n;i++)dfs(i,0);
		ori.clear();
		static int buc[N]; mem(buc,0);
		for(pii it:cur)buc[it.fi]=buc[it.se]=1;
		for(int i=1;i<=n;i++)
			if(buc[i])ori.pb(i);
		int res=query(ori);
		if(res==mx){
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(!tg[i][j])mp[i][j]=0;
			sz=lim;
		}
		else{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(tg[i][j])mp[i][j]=0;
			sz-=lim;
		}
	}
	if(n==2)ans(1,2);
	else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(mp[i][j])ans(i,j);
	}
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();

	return 0;
}