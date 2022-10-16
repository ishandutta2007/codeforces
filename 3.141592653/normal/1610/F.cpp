#include<bits/stdc++.h>
typedef long long ll;
typedef double db;
int n,k;
int x[3333333],y[3333333],l[3333333];
char ans[3333333];
struct pii{int id,t;};
std::vector<pii>v[1111111],w[1111111];
struct edge
{
	int s,t,w;
	std::vector<int>nodes;
	void side(bool _isorder)
	{
		w=0;
		if(_isorder)for(int q:nodes){if(q>0)ans[q]='1';else ans[-q]='2';}
		else for(int q:nodes){if(q>0)ans[q]='2';else ans[-q]='1';}
	}
}E[3333333];
int tot=0;
int d2[3333333],d1[3333333];
bool us[3333333];
void dfs1(int x)
{
	for(;;)
	{
		if(!v[x].size()){E[tot].t=x,d1[x]--;return;}
		pii P=v[x].back();v[x].pop_back();
		int t=P.id,c=t;
		if(t<0)c=-c;
		if(us[c])continue;us[c]=1;
		E[tot].nodes.push_back(t);
		dfs1(P.t);
		break;
	}
}
void dfs2(int x)
{
	for(;;)
	{
		if(!w[x].size()){E[tot].t=x,d2[x]--;return;}
		pii P=w[x].back();w[x].pop_back();
		int t=P.id,c=t;
		if(t<0)c=-c;
		if(us[c])continue;us[c]=1;
		E[tot].nodes.push_back(t);
		dfs2(P.t);
		break;
	}
}
std::vector<pii>z[1111111];
bool vis[3333333];
void dfs(int x,int o=0)
{
	vis[x]=1;
	for(pii&q:z[x])
	{
		int qc=q.id;
		if(q.id<0)qc=-qc;
		if(E[qc].w)
		{
			if(q.id<0)E[qc].side(!o);
			else E[qc].side(o);
		}
		if(!vis[q.t])dfs(q.t,o),o^=1;
	}
}
void Ring1(int x)
{
	for(;;)
	{
		if(!v[x].size())return;
		int t=v[x].back().id,c=t;
		if(t<0)c=-c;
		if(us[c]){v[x].pop_back();continue;}
		ans[c]='1';
		if(t<0)ans[c]='2';
		us[c]=1;
		Ring1(v[x].back().t);
	}	
}
void Ring2(int x)
{
	for(;;)
	{
		if(!w[x].size())return;
		int t=w[x].back().id,c=t;
		if(t<0)c=-c;
		if(us[c]){w[x].pop_back();continue;}
		ans[c]='1';
		if(t<0)ans[c]='2';
		us[c]=1;
		Ring2(w[x].back().t);
	}	
}
void tRing(int x)
{
	while(v[x].size())Ring1(x);
	while(w[x].size())Ring2(x);
}
void solve()
{
	register int i;
	for(i=1;i<=n;i++)
	{
		if(d1[i]&1)tot++,E[tot].s=i,E[tot].w=1,d1[i]--,dfs1(i);
		if(d2[i]&1)tot++,E[tot].s=i,E[tot].w=2,d2[i]--,dfs2(i);
	}
	//for(i=1;i<=n;i++)assert(d1[i]%2==0);
	//for(i=1;i<=n;i++)assert(d2[i]%2==0);
	for(i=1;i<=n;i++)tRing(i);
	for(i=1;i<=tot;i++)
	{
		//printf("{%d %d %d}\n",E[i].s,E[i].t,E[i].w);
		//for(int t:E[i].nodes)printf("%d ",t);puts("!");
		z[E[i].s].emplace_back(pii{i,E[i].t});
		z[E[i].t].emplace_back(pii{-i,E[i].s});
	}
	for(i=1;i<=n;i++)if(!vis[i])dfs(i);
	//for(i=1;i<=tot;i++)assert(!E[i].w);
	//for(i=1;i<=k;i++)assert(us[i]);
	//for(i=1;i<=k;i++)assert(ans[i]);
	puts(ans+1);
}
namespace io
{
	const int N=1<<20;
	char buf[N],*t1=buf,*t2=buf;
	#ifdef StdIO
	#define getc() getchar()
	#else
	#define getc() t1==t2&&(t2=(t1=buf)+fread(buf,1,N,stdin),t1==t2)?EOF:*t1++
	#endif
	inline int read()
	{
		static int an,f;an=0,f=1;
		static char ch;ch=getc();
		while(ch<48||ch>57)ch=='-'?f=-1:0,ch=getc();
		while(ch>=48&&ch<=57)an=(an<<3)+(an<<1)+(ch^48),ch=getc();
		return an*f;
	}
	char buff[N],*T=buff;
	void flush(){fwrite(buff,1,T-buff,stdout);T=buff;}
	inline void putc(char ch){if(T==buff+N)flush();*T++=ch;}
	template<typename o>
	inline void print(o x)
	{
		if(x<0)putc('-'),x=-x;
		if(!x)return putc('0'),void();
		static int st[20],tp;
		while(x)st[++tp]=x%10,x/=10;
		while(tp)putc(st[tp]^48),--tp;
	}
}
using io::read;
int d[1<<20];
int main()
{
	register int i;
	//scanf("%d%d",&n,&k);
	n=read(),k=read();
	//assert((n&1)==0);
	for(i=1;i<=k;i++)
	{
		//scanf("%d%d%d",x+i,y+i,l+i);
		x[i]=read(),y[i]=read(),l[i]=read();
		d[x[i]]+=l[i],d[y[i]]+=l[i]; 
		if(l[i]==1)v[x[i]].emplace_back(pii{i,y[i]}),v[y[i]].emplace_back(pii{-i,x[i]}),d1[x[i]]++,d1[y[i]]++;
		else w[x[i]].emplace_back(pii{i,y[i]}),w[y[i]].emplace_back(pii{-i,x[i]}),d2[x[i]]++,d2[y[i]]++;
	}
	int s=0;
	for(int i=1;i<=n;i++)s+=d[i]&1;
	printf("%d\n",s);
	solve();
}