#include<cstdio>
int n,m,k,X,Y,Mxd,ansx,ansy;bool ok;
int rt[2002][2002]={},mn[2002][2002]={},mx[2002][2002]={};
inline int abs(int x)
{
	return x>0? x:-x;
}
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline void getroot(int rt[],int x)
{
	if(rt[x]==x)return ;
	getroot(rt,rt[x]),rt[x]=rt[rt[x]];
}
inline void upd(int x,int y)
{
	if(x>0 && x<=n && y>0 && y<=m && (abs(X-x)+abs(Y-y)<Mxd || (abs(X-x)+abs(Y-y)==Mxd && ((!ok && (x<ansx || (x==ansx && y<ansy))) || (ok && (y<ansy || (y==ansy && x<ansx)))))))Mxd=abs(X-x)+abs(Y-y),ansx=x,ansy=y;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(n>m)ok=1,swap(n,m);
	while(k--)
	{
		scanf("%d%d",&X,&Y),Mxd=n+m;if(ok)swap(X,Y);
		for(int i=0;i<=Mxd && (X-i>0 || X+i<=n);++i)
		{
			if(X-i>0)
			{
				if(!rt[X-i][Y])upd(X-i,Y);
				else getroot(rt[X-i],Y),upd(X-i,mn[X-i][rt[X-i][Y]]-1),upd(X-i,mx[X-i][rt[X-i][Y]]+1);
			}
			if(X+i<=n)
			{
				if(!rt[X+i][Y])upd(X+i,Y);
				else getroot(rt[X+i],Y),upd(X+i,mn[X+i][rt[X+i][Y]]-1),upd(X+i,mx[X+i][rt[X+i][Y]]+1);
			}
		}
		printf("%d %d\n",ok? ansy:ansx,ok? ansx:ansy),rt[ansx][ansy]=mn[ansx][ansy]=mx[ansx][ansy]=ansy;
		if(ansy-1>0 && rt[ansx][ansy-1])getroot(rt[ansx],ansy-1),mn[ansx][ansy]=mn[ansx][rt[ansx][ansy-1]],rt[ansx][rt[ansx][ansy-1]]=rt[ansx][ansy];
		if(ansy+1<=m && rt[ansx][ansy+1])getroot(rt[ansx],ansy+1),mx[ansx][ansy]=mx[ansx][rt[ansx][ansy+1]],rt[ansx][rt[ansx][ansy+1]]=rt[ansx][ansy];
	}
	return 0;
}