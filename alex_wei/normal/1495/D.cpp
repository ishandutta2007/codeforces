/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

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

const int N=400+5;
const int inf=0x3f3f3f3f;
const int mod=998244353;

int hd[N<<1],nxt[N<<2],to[N<<2],cnt;
void add(int x,int y){
	nxt[++cnt]=hd[x],hd[x]=cnt,to[cnt]=y;
}

int n,m,e[N][N],u[N],v[N],buc[N],vis[N];

void solve(){
	cin>>n>>m,mem(e,0x3f);
	for(int i=1;i<=n;i++)e[i][i]=0;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		e[u[i]][v[i]]=e[v[i]][u[i]]=1;
		add(u[i],v[i]),add(v[i],u[i]);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(e[i][j]>e[i][k]+e[k][j])
					e[i][j]=e[i][k]+e[k][j];
	for(int i=1;i<=n;i++,cout<<endl)
		for(int j=1;j<=n;j++){
			ll cnt=0,ans=1,d=e[i][j]; mem(buc,0),mem(vis,0);
			queue <int> q;
			for(int k=1;k<=n;k++)
				if(e[i][k]+e[j][k]==d)
					cnt++,q.push(k),vis[k]=2;
			if(cnt!=d+1){
				cout<<"0 ";
				continue;
			}
			bool check=1;
			while(!q.empty()){
				int id=q.front(); q.pop();
				for(int z=hd[id];z;z=nxt[z]){
					int tt=to[z];
					if(e[i][id]+1==e[i][tt]&&e[j][id]+1==e[j][tt]){
						buc[tt]++;
						if(!vis[tt])q.push(tt),vis[tt]=1;
					}
				}
			}
			for(int i=1;i<=n;i++)if(vis[i]!=2)ans=ans*buc[i]%mod;
			cout<<ans<<" ";
		} 
}

int main(){
	int t=1;
//	cin>>t;
	while(t--)solve();

	return 0;
}