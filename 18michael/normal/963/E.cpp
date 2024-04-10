#include<bits/stdc++.h>
#define LL long long
#define mod 1000000007
using namespace std;
int r,r2;
LL ans=0;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1},id[108];
LL p[4],ip[4];
LL tmp[108];
LL b[108][108];
LL a[108][108][108];
bool u[108];
inline LL Pow(int a,int b)
{
	if(!b)return 1;
	LL c=Pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline bool check(int x,int y)
{
	return (x-r)*(x-r)+(y-r)*(y-r)<=r*r;
}
inline void work(int &x,int &y,int z)
{
	for(LL c;b[y][z];swap(x,y))
	{
		c=b[x][z]/b[y][z];
		for(int i=z;i<=r2+1;++i)(b[x][i]-=b[y][i]*c)%=mod;
	}
}
inline void Gauss()
{
	for(int i=0;i<=r2;++i)id[i]=i,b[i][r2+1]=-b[i][r2+1];
	for(int i=0;i<=r2;++i)for(int j=i+1;j<=r2;++j)work(id[i],id[j],i);
	for(int i=r2;~i;--i)
	{
		for(int j=i+1;j<=r2;++j)(b[id[i]][r2+1]-=b[id[j]][r2+1]*b[id[i]][j])%=mod;
		(b[id[i]][r2+1]*=Pow(b[id[i]][i],mod-2))%=mod;
	}
}
int main()
{
	scanf("%d%lld%lld%lld%lld",&r,&p[0],&p[1],&p[2],&p[3]),r2=(r<<1),tmp[0]=Pow(p[0]+p[1]+p[2]+p[3],mod-2);
	for(int i=0;i<4;++i)ip[i]=Pow((p[i]*=tmp[0])%=mod,mod-2);
	for(int j=0;j<=r2;++j)for(int i=0;i<=r2;++i)if(check(i,j) && !u[i])a[i][j][i]=u[i]=1;
	for(int j=0,ni,nj;j<=r2;++j)
		for(int i=0;i<=r2;++i)
			if(check(i,j))
			{
				for(int k=0;k<=r2+1;++k)tmp[k]=a[i][j][k];
				--tmp[r2+1];
				for(int o=0;o<3;++o)if(check(ni=i+dx[o],nj=j+dy[o]))for(int k=0;k<=r2+1;++k)(tmp[k]-=p[o]*a[ni][nj][k])%=mod;
				if(check(ni=i,nj=j+1))for(int k=0;k<=r2+1;++k)a[ni][nj][k]=(tmp[k]*ip[3])%mod;
				else for(int k=0;k<=r2+1;++k)b[ni][k]=(tmp[k]*ip[3])%mod;
			}
	Gauss();
	for(int i=0;i<=r2;++i)(ans+=a[r][r][i]*b[id[i]][r2+1])%=mod;
	return 0&printf("%lld",(ans+a[r][r][r2+1]+(mod<<1))%mod);
}