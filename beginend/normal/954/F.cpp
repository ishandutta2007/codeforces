#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int MOD=1000000007;

int n,f[4],tmp[4],w1,vis[20005][4];
LL m,w[20005];
struct Matrix{int a[4][4];}a;
struct data{int a;LL l,r;}p[10005];

void mul(Matrix &c,Matrix a,Matrix b)
{
	memset(c.a,0,sizeof(c.a));
	for (int i=1;i<=3;i++)
		for (int k=1;k<=3;k++)
			for (int j=1;j<=3;j++)
				(c.a[i][j]+=(LL)a.a[i][k]*b.a[k][j]%MOD)%=MOD;
}

Matrix ksm(Matrix x,LL y)
{
	Matrix ans=x;y--;
	while (y)
	{
		if (y&1) mul(ans,ans,x);
		mul(x,x,x);y>>=1;
	}
	return ans;
}

int main()
{
	scanf("%d%I64d",&n,&m);
	w[++w1]=1;w[++w1]=m;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%I64d%I64d",&p[i].a,&p[i].l,&p[i].r);
		w[++w1]=p[i].l-1;w[++w1]=p[i].r;
	}
	sort(w+1,w+w1+1);w1=unique(w+1,w+w1+1)-w-1;
	for (int i=1;i<=n;i++)
	{
		int l=lower_bound(w+1,w+w1+1,p[i].l-1)-w+1,r=lower_bound(w+1,w+w1+1,p[i].r)-w;
		vis[l][p[i].a]++;vis[r+1][p[i].a]--;
	}
	f[2]=1;
	for (int i=2;i<=w1;i++)
	{
		memset(a.a,0,sizeof(a.a));
		for (int j=1;j<=3;j++) vis[i][j]+=vis[i-1][j];
		if (!vis[i][1]) a.a[1][1]=a.a[2][1]=1;
		if (!vis[i][2]) a.a[2][2]=a.a[1][2]=a.a[3][2]=1;
		if (!vis[i][3]) a.a[3][3]=a.a[2][3]=1;
		a=ksm(a,w[i]-w[i-1]);
		tmp[1]=tmp[2]=tmp[3]=0;
		for (int j=1;j<=3;j++)
			for (int k=1;k<=3;k++)
				(tmp[j]+=(LL)f[k]*a.a[k][j]%MOD)%=MOD;
		f[1]=tmp[1];f[2]=tmp[2];f[3]=tmp[3];
	}
	printf("%d",f[2]);
	return 0;
}