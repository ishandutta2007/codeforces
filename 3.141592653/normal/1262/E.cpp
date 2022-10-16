#include<cstdio>
#include<cstring>
int n,m;
char str[1111111],stt[5222222];
int dis[5222222];
#define col(x,y)((x)*(m+2)+(y))
inline void present(int d)
{
	register int i,ii;
	for(i=1;i<=n;i++,puts(""))
		for(ii=1;ii<=m;ii++)
			putchar(dis[col(i,ii)]<=d?'.':'X');
}
int vis[5222222];
int qx[2222222],qy[2222222],rt;
int dx[]={0,0,1,-1,1,1,-1,-1},dy[]={1,-1,0,0,-1,1,-1,1};
inline void expand(int d)
{
	rt=0;
	register int i,ii;
	for(i=0;i<=n+1;i++)
		for(ii=0;ii<=m+1;ii++)
			vis[col(i,ii)]=0;
	for(i=0;i<=n+1;i++)
		for(ii=0;ii<=m+1;ii++)
			if(dis[col(i,ii)]>d)vis[col(i,ii)]=1,rt++,qx[rt]=i,qy[rt]=ii;
	for(i=1;i<=rt;i++)
	{
		int x=qx[i],y=qy[i];
		for(ii=0;ii<8;ii++)
		{
			int xx=x+dx[ii],yy=y+dy[ii];
			if(xx<0||yy<0||xx>n+1||yy>m+1)continue;
			if(!vis[col(xx,yy)])
			{
				vis[col(xx,yy)]=vis[col(x,y)]+1;
				if(vis[col(x,y)]<d)rt++,qx[rt]=xx,qy[rt]=yy;
			}
		}
	}
}
inline bool valid(int g)
{
	expand(g);
	register int i,ii;
	for(i=0;i<=n+1;i++)
		for(ii=0;ii<=m+1;ii++)
			if((vis[col(i,ii)]>0)^(stt[col(i,ii)]=='X'))return 0;
	return 1;
}
inline void getdis()
{
	rt=0;
	register int i,ii;
	for(i=0;i<=n+1;i++)
		for(ii=0;ii<=m+1;ii++)
			if(!dis[col(i,ii)])rt++,qx[rt]=i,qy[rt]=ii;
	for(i=1;i<=rt;i++)
	{
		int x=qx[i],y=qy[i];
		for(ii=0;ii<8;ii++)
		{
			int xx=x+dx[ii],yy=y+dy[ii];
			if(xx<0||yy<0||xx>n+1||yy>m+1)continue;
			if(dis[col(xx,yy)]<=1+dis[col(x,y)])continue;
			dis[col(xx,yy)]=dis[col(x,y)]+1,rt++,qx[rt]=xx,qy[rt]=yy;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	register int i,ii;
	for(i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		for(ii=1;ii<=m;ii++)
			stt[col(i,ii)]=str[ii];
	}for(i=1;i<=n;i++)
		for(ii=1;ii<=m;ii++)
			dis[col(i,ii)]=stt[col(i,ii)]=='X'?1e9:0;
	getdis();
	int l=0,r=(n>m?m:n)>>1;r++;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(valid(mid))l=mid;
		else r=mid;
	}printf("%d\n",l);
	present(l);
}
/*
All the things passing through, leaving me behind.
Where is your fighting heart, std?
*/