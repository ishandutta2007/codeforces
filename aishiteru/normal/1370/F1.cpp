#include<bits/stdc++.h>
#define it register int
#define ct const int
#define il inline
using namespace std;
typedef long long ll;
#define rll register ll
#define cll const ll
typedef double db;
#define rdb register db
#define cdb const db
typedef long double ldb;
typedef unsigned long long ull;
#define pb push_back
#define mkp make_pair
#define pl pair<ll,int> 
#define pi pair<int,int> 
#define fir first
#define sec second
namespace io{
	il char nc(){
		static char buf[100000],*p1=buf,*p2=buf;
		return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++; 
	}
	template <class I> 
	il void fr(I &num){
		num=0;register char c=nc();it p=1;
		while(c<'0'||c>'9') c=='-'?p=-1,c=nc():c=nc();
		while(c>='0'&&c<='9') num=num*10+c-'0',c=nc();
		num*=p;
	} 
	template <class I> 
	il I Max(I p,I q){return p>q?p:q;}
	template <class I> 
	il I Min(I p,I q){return p<q?p:q;}
	template <class I> 
	il I A(I x){return x<0?-x:x;}
	template <class I> 
	il void sp(I&p,I&q){I x=p;p=q,q=x;}
	template <class I>
	il void ckMax(I&p,I q){p=(p>q?p:q);}
	template <class I>
	il void ckMin(I&p,I q){p=(p<q?p:q);}
};
using io :: fr;
using io :: nc;
using io :: Max;
using io :: Min;
using io :: A;
using io :: sp;
using io :: ckMax;
using io :: ckMin;
const int N=1000005;
int h[N],nxt[N],adj[N],u,v,t,rot,T,L,d[N],n;
string tmp;
vector<int> vec,g[N]; 
il void add(){nxt[++t]=h[u],h[u]=t,adj[t]=v,nxt[++t]=h[v],h[v]=t,adj[t]=u;}
il void que(){cout<<'?'<<' '<<vec.size();for(const int &i : vec) cout<<' '<<i;cout<<endl,cout<<flush,cin>>u>>v;}
il void dfs(ct x,ct fa){
	d[x]=d[fa]+1,g[d[x]-1].push_back(x);
	for(it i=h[x],j;i;i=nxt[i])
		if((j=adj[i])^fa) dfs(j,x);
}
il void dfs(ct x,ct fa,ct dis){
	if(!dis) vec.push_back(x);
	for(it i=h[x],j;i;i=nxt[i])
		if((j=adj[i])^fa) dfs(j,x,dis-1);
}
il void ms(){
	it l=L+1>>1,r=L,mid,s=0;
	while(l<=r){
		mid=l+r>>1,vec=g[mid];
		if(vec.empty()){r=mid-1;continue;}
		que(),v<=L?s=u,l=mid+1:r=mid-1;
	}
	vec.clear(),dfs(s,0,L),que(),cout<<'!'<<' '<<s<<' '<<u<<endl,cout<<flush;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;it i;
	while(T--){
		cin>>n,vec.clear();
		for(i=1;i<=n;++i) h[i]=0,vec.push_back(i),g[i].clear();t=0;
		for(i=1;i<n;++i) cin>>u>>v,add();
		que(),rot=u,L=v,dfs(rot,0),ms(),cin>>tmp;
	} 
	return 0;
}