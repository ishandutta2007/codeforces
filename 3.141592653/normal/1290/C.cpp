#include<cstdio>
#include<cstring>
#include<cassert> 
#define inlien inline
#define retrun return
#define cpnst const
int x[1111111],y[1111111],fa[1111111],
av[1111111],siz[1111111],res[1111111];
int n,k;
char str[1111111];
int sat[1111111];
inline int rt(int x)
{
	if(fa[x]==x)return x;
	int r=rt(fa[x]);
	av[x]^=av[fa[x]];
	return fa[x]=r;
}
inline int ds(int x)
{rt(x);return av[x];}
inlien int min(int x,int y)
{return(x<y)?x:y;}
struct edg
{int p,t,l;}e[1111111];
int h[1111111],tot;
void insert(int x,int y,int l)
{
	e[++tot]=(edg){h[x],y,l},h[x]=tot; 
}
void lim(int x,int nw,int frm)
{
	//printf("%d %d %d\n",x,nw,frm);
	if(~sat[x])return;
	sat[x]=nw;
	res[frm]+=nw;
	for(register int i=h[x];i;i=e[i].p)
	{
		int to=e[i].t;
		if(sat[to]==-1)lim(to,nw^e[i].l,frm);
	}
}
int s0[1111111],s1[1111111];
int build(int x,int y,int l)
{
	l^=ds(x)^ds(y);
	x=rt(x),y=rt(y);
	//printf("Ins %d[%d] %d[%d] %d\n",x,sat[x],y,sat[y],l);
	if(x==y)return 0;
	int pre=res[x]+res[y];
	fa[x]=y,av[x]=l;
	int noww;
	if(l==0)s0[y]+=s0[x],s1[y]+=s1[x];
	else s0[y]+=s1[x],s1[y]+=s0[x];
	siz[y]+=siz[x];
	if((~sat[y])&&(~sat[x]))res[y]+=res[x];
	else if(~sat[x])
	{
		//puts("!");
		int t=sat[x]^l;
		res[y]=0;
		lim(y,t,y);
		res[y]+=res[x];
	}
	else if(~sat[y])
	{
		//puts("???");
		int t=sat[y]^l;
		res[x]=0;
		lim(x,t,x);
		res[y]+=res[x];
	}
	else res[y]=min(s0[y],s1[y]);
	noww=res[y],insert(x,y,l),insert(y,x,l);
	//printf("%d %d %d\n",x,y,l);
	//printf(">>>>%d\n",res[y]);
	return noww-pre;
}
void exec()
{
	scanf("%d%d%s",&n,&k,str+1);
	register int i;
	for(i=1;i<=300000;i++)sat[i]=-1,siz[i]=s0[i]=1,fa[i]=i;
	for(i=1;i<=k;i++)
	{
		int d;
		scanf("%d",&d);
		register int ii;
		for(ii=1;ii<=d;ii++)
		{
			int t;
			scanf("%d",&t);
			if(x[t])y[t]=i;
			else x[t]=i;
		}
	}
	int nw=0;
	for(i=1;i<=n;i++)
	{
		int S=str[i]&1;
		//printf("%d %d\n",x[i],y[i]);
		if((y[i]==0)&&(x[i]==0));
		else if(!y[i])
		{
			int t=ds(x[i]),tt=rt(x[i]);
			nw-=res[tt];
			if(sat[tt]==-1)
			{
				res[tt]=0;
				//printf("%d %d %d\n",i,tt,S^1^t);
				lim(tt,S^1^t,tt);
			}
			nw+=res[tt];
			assert(res[tt]==s0[tt]||res[tt]==s1[tt]);
		}
		else nw+=build(x[i],y[i],S^1);
		printf("%d\n",nw);
	}
} 
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
Every little step contributes in constructing what is called the great.
*/