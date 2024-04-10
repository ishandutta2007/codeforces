#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,id[200100],cnt=1;
struct Suffix_Automaton{int ch[26],len,fa;}t[400100];
int Add(int x,int c){
	int xx=++cnt;t[xx].len=t[x].len+1;
	for(;x&&!t[x].ch[c];x=t[x].fa)t[x].ch[c]=xx;
	if(!x){t[xx].fa=1;return xx;}
	int y=t[x].ch[c];
	if(t[y].len==t[x].len+1){t[xx].fa=y;return xx;}
	int yy=++cnt;t[yy]=t[y],t[yy].len=t[x].len+1;
	t[xx].fa=t[y].fa=yy;
	for(;x&&t[x].ch[c]==y;x=t[x].fa)t[x].ch[c]=yy;
	return xx;
}
char s[200100];
int fa[400100],dfn[400100],sz[400100],son[400100],rev[400100],top[400100],dep[400100],tot;
vector<int>v[400100];
void dfs1(int x){
	sz[x]=1;
	for(auto y:v[x]){
		fa[y]=x,dep[y]=dep[x]+1;
		dfs1(y);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x){
	dfn[x]=++tot,rev[tot]=x;if(!top[x])top[x]=x;
	if(son[x])top[son[x]]=top[x],dfs2(son[x]);
	for(auto y:v[x])if(y!=son[x])dfs2(y);
}
#define lson x<<1
#define rson x<<1|1
#define mid ((l+r)>>1)
struct BIT{//a universal template of fenwick tree
	ll s[400100];//the prefix sum of original array
	ll t1[400100],t2[400100];//the unweighted and weighted fenwick
	ll&operator[](const int &x){return s[x];}
	BIT(){memset(s,0,sizeof(s)),memset(t1,0,sizeof(t1)),memset(t2,0,sizeof(t2));}
	void ADD(int x,int y){for(int i=x;i<=cnt;i+=i&-i)t1[i]+=y,t2[i]+=1ll*s[x-1]*y;}
	ll SUM(int x){
		ll sum=0;
		for(int i=x;i;i-=i&-i)sum+=t1[i];
		sum*=s[x];
		for(int i=x;i;i-=i&-i)sum-=t2[i];
		return sum;
	}
	void ADD(int l,int r,int val){if(l<=r)ADD(l,val),ADD(r+1,-val);}
	ll SUM(int l,int r){return SUM(r)-SUM(l-1);}
}bit;
void chainadd(int x,int val){x=id[n-x];while(x)bit.ADD(dfn[top[x]],dfn[x],val),x=fa[top[x]];}
ll chainsum(int x){x=id[n-x];ll ret=0;while(x)ret+=bit.SUM(dfn[top[x]],dfn[x]),x=fa[top[x]];return ret;}
int a[200100];
ll res;
int read(){
	int x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x;
}
void print(ll x){
	if(x<=9)putchar('0'+x);
	else print(x/10),putchar('0'+x%10);
}
int main(){
	n=read(),m=read(),scanf("%s",s),reverse(s,s+n);
	for(int i=0,las=1;i<n;i++)id[i]=las=Add(las,s[i]-'a');
	for(int i=2;i<=cnt;i++)v[t[i].fa].push_back(i);
	dfs1(1),dfs2(1);
//	for(int i=1;i<=cnt;i++)printf("FA:%d SN:%d DP:%d SZ:%d DF:%d RV:%d TP:%d\n",fa[i],son[i],dep[i],sz[i],dfn[i],rev[i],top[i]); 
	for(int i=1;i<=cnt;i++)bit[i]=bit[i-1]+t[rev[i]].len-t[t[rev[i]].fa].len;
//	for(int i=1;i<=cnt;i++)printf("%d ",t[i].len);puts("");
	for(int i=1,A,B;i<=m;i++){
		A=read(),B=read(),res=0;
		for(int i=1;i<=A;i++)chainadd(a[i]=read(),1);
		for(int i=1;i<=B;i++)res+=chainsum(read());
		for(int i=1;i<=A;i++)chainadd(a[i],-1);
		print(res),putchar('\n');
	}
	return 0;
}