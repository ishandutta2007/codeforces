#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int N=100005;
int a[N*4][3][3];
int n,m;
char s[N],c[10];
inline void push_up(int x,int l,int r)
{
	for (int i=0;i<=2;++i)
		for (int j=0;j<=2;++j)
			a[x][i][j]=inf;
	for (int i=0;i<=2;++i)
		for (int j=0;j<=2;++j)
			for (int k=0;k<=2;++k)
				a[x][i][k]=min(a[x][i][k],a[l][i][j]+a[r][j][k]);
}
inline void build(int x,int l,int r)
{
	if (l==r)
	{
		if (s[l]=='a')
		{
			a[x][0][0]=1;
			a[x][0][1]=0;
			a[x][0][2]=inf;
			a[x][1][0]=inf;
			a[x][1][1]=0;
			a[x][1][2]=inf;
			a[x][2][0]=inf;
			a[x][2][1]=inf;
			a[x][2][2]=0;
		}
		if (s[l]=='b')
		{
			a[x][0][0]=0;
			a[x][0][1]=inf;
			a[x][0][2]=inf;
			a[x][1][0]=inf;
			a[x][1][1]=1;
			a[x][1][2]=0;
			a[x][2][0]=inf;
			a[x][2][1]=inf;
			a[x][2][2]=0;
		}
		if (s[l]=='c')
		{
			a[x][0][0]=0;
			a[x][0][1]=inf;
			a[x][0][2]=inf;
			a[x][1][0]=inf;
			a[x][1][1]=0;
			a[x][1][2]=inf;
			a[x][2][0]=inf;
			a[x][2][1]=inf;
			a[x][2][2]=1;
		}
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	push_up(x,x*2,x*2+1);
}
inline void modify(int x,int l,int r,int y)
{
	if (l==r)
	{
		if (s[l]=='a')
		{
			a[x][0][0]=1;
			a[x][0][1]=0;
			a[x][0][2]=inf;
			a[x][1][0]=inf;
			a[x][1][1]=0;
			a[x][1][2]=inf;
			a[x][2][0]=inf;
			a[x][2][1]=inf;
			a[x][2][2]=0;
		}
		if (s[l]=='b')
		{
			a[x][0][0]=0;
			a[x][0][1]=inf;
			a[x][0][2]=inf;
			a[x][1][0]=inf;
			a[x][1][1]=1;
			a[x][1][2]=0;
			a[x][2][0]=inf;
			a[x][2][1]=inf;
			a[x][2][2]=0;
		}
		if (s[l]=='c')
		{
			a[x][0][0]=0;
			a[x][0][1]=inf;
			a[x][0][2]=inf;
			a[x][1][0]=inf;
			a[x][1][1]=0;
			a[x][1][2]=inf;
			a[x][2][0]=inf;
			a[x][2][1]=inf;
			a[x][2][2]=1;
		}
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid)
		modify(x*2,l,mid,y);
	else
		modify(x*2+1,mid+1,r,y);
	push_up(x,x*2,x*2+1);
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	build(1,1,n);
	for (int i=1,p;i<=m;++i)
	{
		scanf("%d%s",&p,c);
		s[p]=c[0];
		modify(1,1,n,p);
		// for (int i=0;i<=2;++i,cout<<endl)
		// 	for (int j=0;j<=2;++j)
		// 		cout<<a[1][i][j]<<' ';
		printf("%d\n",min({a[1][0][0],a[1][0][1],a[1][0][2]}));
	}
	return 0;
}
/*
2 1
ab
1 a

*/