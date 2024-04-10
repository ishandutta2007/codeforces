#include<bits/stdc++.h>
using namespace std;

int maprime[202020];

int numofdiv(int x)
{
	int ret=1;
	while(x>1)
	{
		int tmp=maprime[x],cnt=0;
		while(x%tmp==0)
		{
			cnt++;
			x/=tmp;
		}
		ret*=cnt+1;
	}
	return ret;
}

int gcd(int x,int y)
{
	if(x==0)
		return y;
	if(y==0)
		return x;
	return gcd(y,x%y);
}
bool vis[10][10][10];

long long a[10];
int c1[4]={1,4,5,7};
int c2[4]={2,4,6,7};
int c3[4]={3,5,6,7};
int main()
{
	memset(maprime,0,sizeof(maprime));
	int MAXX=101010;
	for(int i=2;i<=MAXX;i++)
	if(maprime[i]==0)
	{
		for(int j=i;j<=MAXX;j+=i)
			maprime[j]=i;
	}
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		int A,B,C;
		scanf("%d%d%d",&A,&B,&C);
		long long AA=numofdiv(A),BB=numofdiv(B),CC=numofdiv(C);
		long long AB=numofdiv(gcd(A,B)),BC=numofdiv(gcd(B,C)),AC=numofdiv(gcd(A,C));
		long long ABC=numofdiv(gcd(A,gcd(B,C)));
		a[1]=AA-AB-AC+ABC;
		a[2]=BB-AB-BC+ABC;
		a[3]=CC-AC-BC+ABC;
		a[4]=AB-ABC;
		a[5]=AC-ABC;
		a[6]=BC-ABC;
		a[7]=ABC;
		long long ans=0;
		for(int ii=0;ii<4;ii++)
		for(int jj=0;jj<4;jj++)
		for(int kk=0;kk<4;kk++)
		{
			int i=c1[ii];
			int j=c2[jj];
			int k=c3[kk];
			if(i!=j&&j!=k&&i!=k)
			{
				if(vis[i][j][k]==0)
				{
					ans+=a[i]*a[j]*a[k];
					vis[i][j][k]=vis[i][k][j]=vis[j][i][k]=vis[j][k][i]=vis[k][i][j]=vis[k][j][i]=1;
				}
			}
			else if(i==j&&i==k&&j==k)
			{
				if(vis[i][j][k]==0)
				{
					ans+=a[i]*(a[i]-1)*(a[i]-2)/6+a[i]*(a[i]-1)+a[i];
					vis[i][j][k]=vis[i][k][j]=vis[j][i][k]=vis[j][k][i]=vis[k][i][j]=vis[k][j][i]=1;
				}
			}
			else if(i==j)
			{
				if(vis[i][j][k]==0)
				{
					ans+=(a[i]+a[i]*(a[i]-1)/2)*a[k];
					vis[i][j][k]=vis[i][k][j]=vis[j][i][k]=vis[j][k][i]=vis[k][i][j]=vis[k][j][i]=1;
				}
			}
			else if(i==k)
			{
				if(vis[i][j][k]==0)
				{
					ans+=(a[i]+a[i]*(a[i]-1)/2)*a[j];
					vis[i][j][k]=vis[i][k][j]=vis[j][i][k]=vis[j][k][i]=vis[k][i][j]=vis[k][j][i]=1;
				}
			}
			else if(j==k)
			{
				if(vis[i][j][k]==0)
				{
					ans+=(a[j]+a[j]*(a[j]-1)/2)*a[i];
					vis[i][j][k]=vis[i][k][j]=vis[j][i][k]=vis[j][k][i]=vis[k][i][j]=vis[k][j][i]=1;
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}