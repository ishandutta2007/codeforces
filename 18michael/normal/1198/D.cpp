#include<cstdio>
#define inf 60
int n;
char s[52][52];
int f[52][52][52][52];
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline int calc(int sx,int sy,int ex,int ey)
{
	if(f[sx][sy][ex][ey]!=inf)return f[sx][sy][ex][ey];
	if(sx>ex || sy>ey)return (f[sx][sy][ex][ey]=0);
	if(sx==ex && sy==ey)return (f[sx][sy][ex][ey]=(s[sx][sy]=='#'));
	int res=max(ex-sx+1,ey-sy+1);
	for(int i=sx;i<ex;++i)res=min(res,calc(sx,sy,i,ey)+calc(i+1,sy,ex,ey));
	for(int i=sy;i<ey;++i)res=min(res,calc(sx,sy,ex,i)+calc(sx,i+1,ex,ey));
	return (f[sx][sy][ex][ey]=res);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=n;++j)
			for(int k=1;k<=n;++k)
				for(int l=1;l<=n;++l)
					f[i][j][k][l]=inf;
	}
	printf("%d",calc(1,1,n,n));
	return 0;
}