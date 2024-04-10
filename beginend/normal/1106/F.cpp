#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>

typedef long long LL;

const int N=105;
const int MOD=998244353;

int k,n,m;
std::map<int,int> w;
struct Matrix{int a[N][N];}a,b,c;

int ksm(int x,int y,int p)
{
    int ans=1;
    while (y)
    {
        if (y&1) ans=(LL)ans*x%p;
        x=(LL)x*x%p;y>>=1;
    }
    return ans;
}

int solve(int p,int b,int n)
{
    int ny=ksm(b,p-2,p),m=sqrt(p);
    w.clear();
    int v=n;w[n]=-1;
    for (int i=1;i<m;i++)
    {
        v=(LL)v*ny%p;
        if (!w[v]) w[v]=i;
    }
    b=ksm(b,m,p);v=1;
    for (int i=0;i<=m;i++)
    {
        int x=w[v];
        if (x)
        {
            if (x==-1) return i*m;
            else return i*m+x;
        }
        v=(LL)v*b%p;
    }
    return -1;
}

int BSGS(int p,int b,int n)
{
	return solve(p,b,n);
}

void mul1()
{
	for (int i=1;i<=k;i++)
		for (int j=1;j<=k;j++)
			c.a[i][j]=0;
	for (int l=1;l<=k;l++)
		for (int i=1;i<=k;i++)
			for (int j=1;j<=k;j++)
				(c.a[i][j]+=(LL)a.a[i][l]*b.a[l][j]%(MOD-1))%=(MOD-1);
	for (int i=1;i<=k;i++)
		for (int j=1;j<=k;j++)
			b.a[i][j]=c.a[i][j];
}

void mul2()
{
	for (int i=1;i<=k;i++)
		for (int j=1;j<=k;j++)
			c.a[i][j]=0;
	for (int l=1;l<=k;l++)
		for (int i=1;i<=k;i++)
			for (int j=1;j<=k;j++)
				(c.a[i][j]+=(LL)a.a[i][l]*a.a[l][j]%(MOD-1))%=(MOD-1);
	for (int i=1;i<=k;i++)
		for (int j=1;j<=k;j++)
			a.a[i][j]=c.a[i][j];
}

void ksm(int y)
{
	for (int i=1;i<=k;i++) b.a[i][i]=1;
	while (y)
	{
		if (y&1) mul1();
		y>>=1;mul2();
	}
}

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y); 
}

void exgcd(int x,int y,int &a,int &b)
{
    if (!y) {a=1;b=0;return;}
    exgcd(y,x%y,a,b);
    int tmp=a;a=b;b=tmp-(x/y)*b;
}

int main()
{
	scanf("%d",&k);
	for (int i=1;i<=k;i++) scanf("%d",&a.a[k-i+1][k]);
	scanf("%d%d",&n,&m);
	if (m==1) {puts("1");return 0;} 
	for (int i=1;i<k;i++) a.a[i+1][i]=1;
	ksm(n-k);
	int u=b.a[k][k],y=BSGS(MOD,3,m),p=MOD-1;
	int d=gcd(u,p);
	if (y%d>0) {puts("-1");return 0;}
	int t1,t2;
	exgcd(u,p,t1,t2);
	t1=((LL)t1*(y/d)%p+p)%p;
	printf("%d\n",ksm(3,t1,MOD));
	return 0;
}