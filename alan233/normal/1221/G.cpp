// naive problem
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1048576;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,cnt,cnt2,bar,lim;
ll e[40],ans,val[maxn];
bool ind[40],vis[40],col[40],flag=true;
void dfs(int u){
	vis[u]=true;
	FOR(v,0,n-1) if((e[u]>>v)&1){
		if(!vis[v]) col[v]=col[u]^1,dfs(v);
		else{
			if(col[v]!=(col[u]^1)) flag=false;
		}
	}
}
void dfs1(int dep,ll st,ll used){
	if(dep==bar) return void(val[(~st)&(lim-1)]++);
	dfs1(dep-1,st,used);
	if(!((st>>dep)&1)) dfs1(dep-1,st|e[dep],used|1<<dep);
}
void dfs2(int dep,ll st,ll used){
	if(dep==bar+1) return void(ans-=2*val[used&(lim-1)]);
	dfs2(dep+1,st,used);
	if(!((st>>dep)&1)) dfs2(dep+1,st|e[dep],used|1<<dep);
}
int main(){
	n=read();m=read();
	if(!m) return puts("0"),0;
	FOR(i,0,n-1) ind[i]=true;
	FOR(i,1,m){
		int u=read()-1,v=read()-1;
		e[u]|=1ll<<v;e[v]|=1ll<<u;
		ind[u]=ind[v]=false;
	}
	FOR(i,0,n-1) if(ind[i]) cnt2++;
	FOR(i,0,n-1) if(!vis[i]) cnt++,dfs(i);
	ans=(1ll<<n)-(1ll<<cnt)+(1ll<<cnt2)+(1ll<<cnt2)+(flag?1ll<<cnt:0);
	bar=(n-1)/2;lim=1<<(bar+1);
	dfs1(n-1,0,0);
	for(int i=1;i<lim;i<<=1)
		for(int j=0;j<lim;j+=i<<1)
			FOR(k,0,i-1) val[j+k]+=val[i+j+k];
	dfs2(0,0,0);
	printf("%lld\n",ans);
}