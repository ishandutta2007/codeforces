#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,len,las=1,tot=1,edge_t=0,mxp,mxr=0;LL ans;
int la[2000002]={},l[100002],cnt[2000002]={},z[1000002]={};
char s[1000002];
struct aaa
{
	int fa,len;
	unordered_map<char,int> to;
}a[2000002];
struct bbb
{
	int to,nx;
}edge[2000002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(bbb){y,la[x]},la[x]=edge_t;
}
inline void add(int c)
{
	int p=las,np,q,nq;
	las=np=(++tot),a[np].len=a[p].len+1;
	while(p && !a[p].to.count(c))a[p].to[c]=np,p=a[p].fa;
	if(!p)a[np].fa=1;
	else
	{
		q=a[p].to[c];
		if(a[q].len==a[p].len+1)a[np].fa=q;
		else
		{
			nq=(++tot),a[nq]=a[q],a[nq].len=a[p].len+1,a[np].fa=a[q].fa=nq;
			while(p && a[p].to[c]==q)a[p].to[c]=nq,p=a[p].fa;
		}
	}
}
inline void dfs(int x)
{
	for(int i=la[x],v;i;i=edge[i].nx)dfs(v=edge[i].to),cnt[x]+=cnt[v];
}
int main()
{
	scanf("%s%d",s,&n),len=strlen(s);
	for(int i=0;i<len;++i)add(s[i]-'a'),++cnt[las];
	for(int i=1;i<=n;++i)scanf("%s",s+l[i-1]),l[i]=l[i-1]+strlen(s+l[i-1]);
	for(int i=2;i<=tot;++i)add_edge(a[i].fa,i);
	dfs(1);
	for(int i=1,now;i<=n;++i)
	{
		now=1,ans=len=0;
		for(int j=l[i-1];j<l[i];++j)
		{
			while(now>1 && !a[now].to.count(s[j]-'a'))now=a[now].fa,len=a[now].len;
			if(a[now].to.count(s[j]-'a'))now=a[now].to[s[j]-'a'],++len;
		}
		for(int j=l[i-1]+1;j<l[i];++j)
		{
			if(j<=mxr)z[j]=min(z[l[i-1]+j-mxp],2*l[i]-l[i-1]-j);
			while(j+z[j]<2*l[i]-l[i-1] && s[l[i-1]+z[j]-(l[i-1]+z[j]>=l[i]? l[i]-l[i-1]:0)]==s[j+z[j]-(j+z[j]>=l[i]? l[i]-l[i-1]:0)])++z[j];
			if(j+z[j]-1>mxr)mxp=j,mxr=j+z[j]-1;
		}
		for(int j=l[i-1];j<l[i];++j)
		{
			if(a[now].len>=l[i]-l[i-1] && len==l[i]-l[i-1])ans+=cnt[now];
			if(z[j+1]>=l[i]-l[i-1])break;
			while(now>1 && !a[now].to.count(s[j]-'a'))now=a[now].fa,len=a[now].len;
			if(a[now].to.count(s[j]-'a'))now=a[now].to[s[j]-'a'],++len;
			len=min(len,l[i]-l[i-1]);
			while(now>1 && a[a[now].fa].len>=l[i]-l[i-1])now=a[now].fa;
		}
		printf("%lld\n",ans);
	}
	return 0;
}