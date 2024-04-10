/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)

//using int = long long
//using i128 = __int128;

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
#define Time 1.0*clock()/CLOCKS_PER_SEC

pii operator + (pii a,pii b){return {a.fi+b.fi,a.se+b.se};}
pll operator + (pll a,pll b){return {a.fi+b.fi,a.se+b.se};}

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

const int N=1e6+5;

// Suffix_Automaton
int cnt,las;
int fa[N],len[N],son[N][26];
ll val[N];
vector <int> e[N];
void ins(int it,int v){
	int p=las,cur=++cnt;
	len[cur]=len[las]+1,las=cur,val[cur]=v;
	while(p&&!son[p][it])son[p][it]=cur,p=fa[p];
	if(!p)return fa[cur]=1,void();
	int q=son[p][it];
	if(len[p]+1==len[q])return fa[cur]=q,void();
	int cl=++cnt;
	fa[cl]=fa[q],fa[q]=fa[cur]=cl,len[cl]=len[p]+1;
	mcpy(son[cl],son[q]);
	while(p&&son[p][it]==q)son[p][it]=cl,p=fa[p];
} void build(string s,int v){
	las=1;
	for(int i=0;i<s.size();i++)ins(s[i]-'a',v);
} void dfs(int id){
	for(int it:e[id])dfs(it),val[id]+=val[it];
}

int n;
ll ans;
string s[N];
int main(){
	cin>>n,cnt=1;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1,c;i<=n;i++)cin>>c,build(s[i],c);
	for(int i=1;i<=cnt;i++)e[fa[i]].pb(i);
	dfs(1); for(int i=1;i<=cnt;i++)if(len[fa[i]]!=len[i])ans=max(ans,len[i]*val[i]);
	cout<<ans<<endl;
	return 0;
}