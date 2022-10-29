#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
namespace Istream
{
	char buffer[4000000],*s,*t;
	inline char Getchar()
	{
		if(s==t)
		{
			t=(s=buffer)+fread(buffer,1,4000000,stdin);
			if(s==t)
				return EOF;
		}
		return *s++;
	}
	inline void gi(int &x)
	{
		char c;
		while((c=Getchar())<'0'||c>'9');
		x=c-'0';
		while((c=Getchar())>='0'&&c<='9')
			x=x*10+c-'0';
	}
}
using Istream :: gi;
int n,K,i,j,k,u[4005][4005],f[4005][805],w[4005][4005],s[4005][4005];
void work(int l1,int r1,int l2,int r2)
{
	if(l1>r1)
		return;
	int mid=l1+r1>>1,k,x;
	for(k=l2+1,x=l2;k<=r2;++k)
		if(f[k][mid-1]+w[k+1][i]<f[x][mid-1]+w[x+1][i])
			x=k;
	f[i][mid]=f[x][mid-1]+w[x+1][i];
	work(l1,mid-1,l2,x);
	work(mid+1,r1,x,r2);
}
int main()
{
	gi(n);gi(K);
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		{
			gi(u[i][j]);
			s[i][j]=s[i][j-1]+(u[j][i]=u[i][j]);
		}
	}
	for(i=1;i<=n;++i)
	{
		w[i][i]=0;
		for(j=i+1;j<=n;++j)
			w[i][j]=w[i][j-1]+(s[j][j]-s[j][i-1]);
	}
	for(i=0;i<=n;++i)
		for(j=0;j<=K;++j)
			f[i][j]=1000000000;
	f[0][0]=0;
	for(i=1;i<=n;++i)
	{
		work(1,min(i,K),0,i-1);
		/*for(j=1;j<=i&&j<=K;++j)
		{
			for(k=0;k<i;++k)
				f[i][j]=min(f[i][j],f[k][j-1]+w[k+1][i]);
			for(k=0;k<i;++k)
				if(f[i][j]==f[k][j-1]+w[k+1][i])
					break;
			printf("%d ",k);
		}*/
	}
	printf("%d",f[n][K]);
	return 0;
}