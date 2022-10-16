#include<bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

namespace IO{
	char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<24],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)
	inline ll read(){
		ll x=0; bool sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	inline void print(ll x){
		if(x<0)pc('-'),print(-x);
		else{
			if(x>9)print(x/10);
			pc(x%10+'0');
		}
	}
} using namespace IO;

const int N=1e5+5;
const int L=60;
const ll mod=1e9+7;
const ll iv2=mod+1>>1;

int size,cont;
ll sx,a[L];
void insert(ll x){
	for(int i=L-1;~i;i--)
		if(x>>i&1){
			if(a[i]){x^=a[i]; continue;}
			for(int j=i-1;~j;j--)if(x>>j&1)x^=a[j];
			for(int j=i+1;j<L;j++)if(a[j]>>i&1)a[j]^=x;
			return a[i]=x,size++,void();
		}
}

int n,m,cnt,hd[N],nxt[N<<2],to[N<<2];
ll val[N<<2],ans;
void add(int u,int v,ll w){
	nxt[++cnt]=hd[u],hd[u]=cnt;
	to[cnt]=v,val[cnt]=w;
}

bool vis[N]; ll cur[N];
int len,c[N];
void dfs(int id,ll w){
	vis[id]=1,cur[id]=w,c[++len]=id;
	for(int i=hd[id];i;i=nxt[i]){
		int it=to[i];
		if(vis[it])insert(w^val[i]^cur[it]);
		else dfs(it,w^val[i]);
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u=read(),v=read(); ll t=read();
		add(u,v,t),add(v,u,t);
	} for(int i=1;i<=n;i++) if(!vis[i]){
		size=0,sx=0,cont=0,len=0,mem(a,0,L);
		dfs(i,0),cont=(1ll<<size)%mod;
		for(int i=0;i<L;i++)sx|=a[i];
		for(int i=0;i<L;i++){
			ll ze=0,on=0,pw=(1ll<<i)%mod,same,diff;
			for(int j=1;j<=len;j++)cur[c[j]]>>i&1?on++:ze++;
			same=(on*(on-1)/2+ze*(ze-1)/2)%mod,diff=(on*ze)%mod;
			if(sx>>i&1)ans=(ans+(same+diff)*pw%mod*cont%mod*iv2%mod)%mod;
			else ans=(ans+diff*pw%mod*cont%mod)%mod;
		}
	} cout<<ans<<endl;
	return 0;
}
////