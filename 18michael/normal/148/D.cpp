#include<cstdio>
int w,b;
double f[1002][1002];
inline void init()
{
	for(int i=0;i<=w;++i)
		for(int j=0;j<=b;++j)
			f[i][j]=-1;
	for(int i=1;i<=w;++i)f[i][0]=1;
	for(int i=0;i<=b;++i)f[0][i]=0;
}
inline double dp(int x,int y)
{
	if(x<0 || y<0)return 0;
	if(f[x][y]>=0)return f[x][y];
	f[x][y]=1.0*x/(x+y);
	if(x+y>2)
	{
		f[x][y]+=1.0*y/(x+y)*(y-1)/(x+y-1)*(y-2)/(x+y-2)*dp(x,y-3);
		f[x][y]+=1.0*y/(x+y)*(y-1)/(x+y-1)*x/(x+y-2)*dp(x-1,y-2);
	}
	return f[x][y];
}
int main()
{
	scanf("%d%d",&w,&b),init(),printf("%.9lf",dp(w,b));
	return 0;
}