#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=400005;
int n; 
int f[4][N];
int g[4][N];
int sz[5];
int calc (int A,int B,int C,int D)
{
	if (A>sz[3]||B>sz[1]||C>sz[2]||D>sz[0]) return -1;
	if (A<0||B<0||C<0||D<0) return -1;
	return g[3][A]+g[1][B]+g[2][C]+g[0][D];
}
int main()
{
	scanf("%d",&n);
	for (int u=1;u<=n;u++)
	{
		char ss[5];
		int a;
		scanf("%s%d",ss,&a);
		if (ss[0]=='0'&&ss[1]=='0') f[0][++sz[0]]=a;//D
		if (ss[0]=='0'&&ss[1]=='1') f[1][++sz[1]]=a;//B
		if (ss[0]=='1'&&ss[1]=='0') f[2][++sz[2]]=a;//C
		if (ss[0]=='1'&&ss[1]=='1') f[3][++sz[3]]=a;//A
	}
	for (int u=0;u<=3;u++) 	
	{
		sort(f[u]+1,f[u]+1+sz[u]);	
		reverse(f[u]+1,f[u]+1+sz[u]);
		for (int i=1;i<=sz[u];i++) g[u][i]=g[u][i-1]+f[u][i];
	}
	int ans=0;
	for (int x=0;x<=sz[3];x++)
	{
		int A,B,C,D;
		//B-C;
		if (sz[1]>=sz[2])
		{
			A=sz[3];D=A-x;C=sz[2];B=min(sz[1],C+x);
			ans=max(ans,calc(A,B,C,D));
		}
		else//C-B
		{
			A=sz[3];D=A-x;B=sz[1];C=min(sz[2],B+x);
			ans=max(ans,calc(A,B,C,D));
		}
	}
	printf("%d\n",ans);
	return 0;
}