#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
#include<bitset>
typedef std::bitset<1020>BIT;
BIT f[1111],g[1111],vis[1111],lv,us;
int c[1111],ref[1111];
int main()
{
	int n;
	scanf("%d",&n);
	register int i,ii;
	bool ff=1;
	for(i=1;i<=n;i++)
	{
		int op;
		scanf("%d",&op),c[i]=op;
		if(op^n)ff=0;
		for(;op--;)
		{int t;scanf("%d",&t),f[i][t]=1;}
	}if(ff){for(i=2;i<=n;i++)printf("1 %d\n",i);return 0;}
	int cc=0,cx=0,cy=0;
	for(i=1;i<=n;i++)vis[i][i]=1;
	for(i=1;i<=n;i++)
		for(ii=i+1;ii<=n;ii++)
		{
			BIT tp=f[i]&f[ii];
			if(tp.count()==2)
			{
				int x=tp._Find_first(),y=tp._Find_next(x);
				lv[x]=lv[y]=1;
				if(!vis[x][y])printf("%d %d\n",x,y),cc++,cx=x,cy=y;
				vis[x][y]=vis[y][x]=1;
			}
		}
	c[0]=1e9;
	for(i=1;i<=n;i++)
		if(!lv[i])
		{
			for(ii=1;ii<=n;ii++)
				if(!us[ii])if(f[ii][i]&&c[ii]<c[ref[i]])ref[i]=ii;
			us[ref[i]]=1;
			g[i]=f[ref[i]];
		}
			
	if(cc==1)
	{
		int t=1;
		for(i=1;i<=n;i++)
			if(!lv[i])t=i;
		for(i=1;i<=n;i++)
			if(!lv[i])
			{
				if(g[i]==g[t])printf("%d %d\n",cx,i);
				else printf("%d %d\n",cy,i);
			}
		return 0;
	}for(i=1;i<=n;i++)
		if(!lv[i])
		{
			BIT tp=g[i]&lv;
			for(ii=1;ii<=n;ii++)
				if(lv[ii])
					if(vis[ii]==tp)
					{printf("%d %d\n",i,ii);goto T;}
			T:;
		}
}
/*
Just go for it.
*/