#include<bits/stdc++.h>
typedef double db;
const double eps=1e-9;
namespace netWork
{
	int h[1111111],frm[1111111],frn[1111111],tot;
	db dis[1111111];
	struct ed{int p,t,l;db w;}e[4444444];
	void __ins(int x,int y,int l,db w){e[++tot]=(ed){h[x],y,l,w},h[x]=tot;}
	void ins(int x,int y,int l,db w){__ins(x,y,l,w),__ins(y,x,0,-w);}
	int S,T,V;
	void clear(int N,int _S,int _T)
	{
		for(register int i=1;i<=N;i++)h[i]=0;
		tot=1,V=N,S=_S,T=_T;
	}
	bool isin[1111111];
	db spfa()
	{
		register int i;
		for(i=1;i<=V;i++)dis[i]=-1e9;
		std::queue<int>q;q.push(S),dis[S]=0,isin[S]=1;
		for(;!q.empty();q.pop())
		{
			int p=q.front();
			for(i=h[p];i;i=e[i].p)
			{
				if(!e[i].l)continue;
				int t=e[i].t;
				if(dis[t]+eps<dis[p]+e[i].w)
				{
					dis[t]=dis[p]+e[i].w,frn[t]=i,frm[t]=p;
					if(!isin[t])isin[t]=1,q.push(t);
				}
			}isin[p]=0;
		}return dis[T];
	}
	void dec()
	{for(register int i=T;i;i=frm[i])e[frn[i]].l--,e[frn[i]^1].l++;}
	db mcmf()
	{
		db Sum=0;
		for(register int i=1;;i++)
		{
			db r=spfa();
			if(r<eps)return Sum;
			Sum+=r,dec();
		}
	}
}
int n,a,b;
db w1[111111],w2[111111];
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	register int i;
	netWork::clear(n+4,n+1,n+2),netWork::ins(n+1,n+3,a,0),netWork::ins(n+1,n+4,b,0);
	for(i=1;i<=n;i++)scanf("%lf",w1+i);
	for(i=1;i<=n;i++)scanf("%lf",w2+i),
	netWork::ins(i,n+2,1,0),netWork::ins(i,n+2,1,-w1[i]*w2[i]),
	netWork::ins(n+3,i,1,w1[i]),netWork::ins(n+4,i,1,w2[i]);
	printf("%.9lf\n",netWork::mcmf());
}