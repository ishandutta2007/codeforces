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

const int S=4e4+5;
const int N=1e3+5;

int n,x,cnt,ans=S,son[S][10],f[S],ed[S],g[N][S];
string s;
void ins(string s){
	int p=0;
	for(char it:s){
		if(!son[p][it-'0'])son[p][it-'0']=++cnt;
		p=son[p][it-'0'];
	} ed[p]=1;
} void build(){
	queue <int> q;
	for(int i=0;i<10;i++)if(son[0][i])q.push(son[0][i]);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=0;i<10;i++)
			if(son[t][i])q.push(son[t][i]),f[son[t][i]]=son[f[t]][i];
			else son[t][i]=son[f[t]][i];
		ed[t]|=ed[f[t]];
	} 
} bool check(string s){
	for(int i=0;i<s.size();i++)
		for(int j=i;j<s.size();j++){
			int cnt=0;
			for(int k=i;k<=j;k++)cnt+=s[k]-'0';
			if(cnt<x&&x%cnt==0)return 0;
		} return 1;
} void dfs(int num,string s=""){
	if(num==x){
		if(check(s))ins(s);
		return;
	} for(int i=1;i<10;i++)
		if(num+i<=x)
			dfs(num+i,s+(char)(i+'0'));
}

int main(){
	cin>>s>>x,dfs(0),build();
	mem(g,0x3f),g[0][0]=0;
	for(int i=0;i<s.size();i++)
		for(int j=0;j<=cnt;j++){
			int p=son[j][s[i]-'0'];
			if(!ed[p])g[i+1][p]=min(g[i+1][p],g[i][j]);
			g[i+1][j]=min(g[i+1][j],g[i][j]+1);
		}
	for(int i=0;i<=cnt;i++)ans=min(ans,g[s.size()][i]);
	cout<<ans<<endl;
	return 0;
}