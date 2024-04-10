#include<cstdio>
#define LL long long
#define mod 51123987
int n,las,tot,edge_t,eto_t;LL ans=0;
int la[2000002],to[2000002],lato[2000002],pre[2000002],pos[2000002],tim[2000002];
char s[2000002];
struct aaa
{
	int fail,len,c;
}t[2000002];
struct bbb
{
	int to,nx;
}edge[2000002],eto[2000002];
inline void swap(char &a,char &b)
{
	char c=a;a=b,b=c;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(bbb){y,la[x]},la[x]=edge_t;
}
inline void add_eto(int x,int y)
{
	eto[++eto_t]=(bbb){y,lato[x]},lato[x]=eto_t;
}
inline void dfs(int x)
{
	for(int i=la[x],v;i;i=edge[i].nx)
		v=edge[i].to,tim[v]+=tim[x],dfs(v);
}
inline int find(int x,int c)
{
	for(int i=lato[x],v;i;i=eto[i].nx)
		if(t[eto[i].to].c==c)
			return i;
	return 0;
}
inline void PAM(char s[])
{
	for(int i=0;i<=tot;++i)la[i]=lato[i]=tim[i]=0;
	las=0,tot=1,edge_t=0,eto_t=0,t[0].fail=t[1].fail=1,t[0].len=0,t[1].len=-1;
	for(int i=0,j,c,p,q;i<n;++i)
	{
		c=s[i]-'a';
		while((j=i-t[las].len-1)<0 || s[j]!=s[i])las=t[las].fail;
		if(!(q=find(las,c)))
		{
			add_eto(las,p=(++tot)),t[tot].c=c,t[p].len=t[las].len+2,las=t[las].fail;
			while((j=i-t[las].len-1)<0 || s[j]!=s[i])las=t[las].fail;
			q=find(las,c),t[p].fail=(eto[q].to==p? 0:eto[q].to),las=p,add_edge(t[p].fail,p);
		}
		else las=eto[q].to;
		pos[i]=las,tim[las]=1;
	}
	dfs(0);
}
int main()
{
	scanf("%d",&n),scanf("%s",s),PAM(s);
	for(int i=0;i<n;++i)pre[i]=tim[pos[i]],ans=(ans+pre[i])%mod;
	ans=(ans*(ans-1)/2)%mod;
	for(int i=(n-1)/2;~i;--i)swap(s[i],s[n-i-1]);PAM(s);
	for(int i=1;i<n;++i)pre[i]=(pre[i]+pre[i-1])%mod;
	for(int i=n-2;~i;--i)ans=(ans-1LL*pre[i]*tim[pos[n-i-2]])%mod;
	printf("%lld",(ans+mod)%mod);
	return 0;
}