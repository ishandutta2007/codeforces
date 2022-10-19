#include<cstdio>
#include<cmath>
#define Mx 9
#define eps 1e-6
int n,m,t,l,r,mid;
int c[1002][1002];
int f[1002][1002][10][10];
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline int max(int x,int y)
{
	return x>y? x:y;
}
inline int getmx(int sx,int sy,int ex,int ey)
{
	int lx=log2(ex-sx+1)+eps,ly=log2(ey-sy+1)+eps;
	return max(max(f[sx][sy][lx][ly],f[sx][ey-(1<<ly)+1][lx][ly]),max(f[ex-(1<<lx)+1][sy][lx][ly],f[ex-(1<<lx)+1][ey-(1<<ly)+1][lx][ly]));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)scanf("%d",&c[i][j]),c[i][j]+=c[i][j-1];
		for(int j=1;j<=m;++j)c[i][j]+=c[i-1][j];
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			for(l=1,r=min(n-i+1,m-j+1);l<=r;)
			{
				mid=((l+r)>>1);
				if(c[i+mid-1][j+mid-1]-c[i-1][j+mid-1]-c[i+mid-1][j-1]+c[i-1][j-1]==mid*mid)l=mid+1;
				else r=mid-1;
			}
			f[i][j][0][0]=r;
		}
	for(int i=1;i<=Mx;++i)
		for(int k=1;k+(1<<i)-1<=n;++k)
			for(int l=1;l<=m;++l)
				f[k][l][i][0]=max(f[k][l][i-1][0],f[k+(1<<(i-1))][l][i-1][0]);
	for(int i=0;i<=Mx;++i)
		for(int j=1;j<=Mx;++j)
			for(int k=1;k+(1<<i)-1<=n;++k)
				for(int l=1;l+(1<<j)-1<=m;++l)
					f[k][l][i][j]=max(f[k][l][i][j-1],f[k][l+(1<<(j-1))][i][j-1]);
	scanf("%d",&t);
	for(int sx,sy,ex,ey;t--;)
	{
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		for(l=1,r=min(ex-sx+1,ey-sy+1);l<=r;)
		{
			mid=((l+r)>>1);
			if(getmx(sx,sy,ex-mid+1,ey-mid+1)>=mid)l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",r);
	}
	return 0;
}