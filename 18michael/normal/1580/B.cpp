#include<cstdio>
#include<cstring>
int n,m,k,p;
int mx[102],fac[102];
int C[102][102],Mx[102][102];
int f[102][102][102];
inline int min(int x,int y)
{
	return x<y? x:y;
}
inline void init()
{
	C[0][0]=fac[0]=1,mx[0]=0;
	for(int i=1;i<=n;++i)
	{
		C[i][0]=1,mx[i]=min((mx[i-1]<<1)+1,n-i+1),fac[i]=(1LL*fac[i-1]*i)%p;
		for(int j=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
		for(int j=1;j<=n;++j)Mx[i][j]=min(mx[i],(j+1)/2);
	}
}
inline int dp(int x,int y,int z)
{
	if(~f[x][y][z])return f[x][y][z];
	if(!x)return f[x][y][z]=(!y);
	if(z==1)return f[x][y][z]=(y==1? fac[x]:0);
	if(!z || y>Mx[z][x])return f[x][y][z]=0;
	f[x][y][z]=0;
	for(int a=0;a<x;++a)
		for(int b=0;b<=y;++b)
			f[x][y][z]=(f[x][y][z]+((1LL*C[x-1][a]*dp(a,b,z-1))%p)*dp(x-a-1,y-b,z-1))%p;
	return f[x][y][z];
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&p),init(),memset(f,-1,sizeof(f));
	return 0&printf("%d",dp(n,k,m));
}