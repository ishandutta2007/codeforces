#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAX=(1<<30);
const int N=45;
int n,m,q;
char A[N][N];
int r[N][N];//1 
int mp[N][N];// 
int mp1[N][N];//
int R[N][N];
int D[N][N];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int u=1;u<=n;u++)
		scanf("%s",A[u]+1);
	for (int u=n;u>=1;u--)
		for (int i=m;i>=1;i--)
		{
			if (A[u][i]=='1') r[u][i]=0;
			else r[u][i]=r[u][i+1]+1;
			D[u][i]=u;
			while (r[u][i]<r[D[u][i]+1][i]) D[u][i]=D[D[u][i]+1][i];
		}
	while (q--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int ans=0;
		memset(mp1,0,sizeof(mp1));
		for (int u=c;u>=a;u--)
		{
			for (int i=b;i<=d;i++)
			{
				mp1[u][i]=mp1[min(c,D[u][i])+1][i]+(min(c,D[u][i])-u+1)*min(d-i+1,r[u][i]);
			/*	printf("%d %d %d\n",u,i,mp1[min(d,D[u][i])+1][i]+(D[u][i]-u+1)*r[u][i]);
				system("pause");*/
				ans=ans+mp1[u][i];
			}
		}
		printf("%d\n",ans);
	}	
	return 0;
}