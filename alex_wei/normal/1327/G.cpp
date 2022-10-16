/*
	Powered by C++11.
	Author : Alex_Wei.
*/


//#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mpi make_pair
#define vint vector <int>
#define vpii vector <pii>
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

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
	void print(ll x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math{
	const int mod=99824353;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b){ll s=1,m=a; while(b){if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1; for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]); for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

using namespace IO;
//using namespace math;

const int N=1e3+5;
const int S=4e5+5;
const int K=14;

int k,cnt,son[N][26],f[N],val[N];
void ins(string s,int v){
	int p=0;
	for(char it:s){
		if(!son[p][it-'a'])son[p][it-'a']=++cnt;
		p=son[p][it-'a'];
	} val[p]+=v;
}
void build(){
	queue <int> q;
	for(int i=0;i<26;i++)if(son[0][i])q.push(son[0][i]);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=0;i<26;i++)
			if(son[t][i])f[son[t][i]]=son[f[t]][i],q.push(son[t][i]);
			else son[t][i]=son[f[t]][i];
		val[t]+=val[f[t]];
	}
}

ll ans=-1e18,g[N][1<<K],vv[N][K+1];
int q,bt[1<<K],pos[K+2],jp[N][K+1];
string s;
int main(){
	cin>>k;
	for(int i=1;i<=k;i++){
		int v; cin>>s>>v,ins(s,v);
	} build(),cin>>s;
	for(int i=1;i<1<<K;i++)bt[i]=bt[i-(i&-i)]+1;
	for(int i=0;i<s.size();i++)if(s[i]=='?')pos[++q]=i;
	pos[0]=-1,pos[q+1]=s.size();
	mem(g,0x9f),mem(jp,-1),g[0][0]=0;
	for(int i=0;i<1<<K;i++){
		int c=bt[i];
		if(c>q)continue;
		for(int j=0;j<=cnt;j++){
			if(g[j][i]<-1e17)continue;
			int p=j; ll v=0;
			if(~jp[j][c])v=vv[j][c],p=jp[j][c];
			else{
				for(int k=pos[c]+1;k<pos[c+1];k++)v+=val[p=son[p][s[k]-'a']];
				jp[j][c]=p,vv[j][c]=v;
			}
			if(c==q)ans=max(ans,g[j][i]+v);
			else for(int k=0;k<K;k++)if(!(i>>k&1)){
				int ps=son[p][k],msk=i+(1<<k);
				g[ps][msk]=max(g[ps][msk],g[j][i]+v+val[ps]);
			}
		}
	} cout<<ans<<endl;
	return flush(),0;
}