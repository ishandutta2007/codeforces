#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=305;
const int MOD=1e9+7;
int add (int x,int y)   {x=x+y;return x>=MOD?x-MOD:x;}
int mul (int x,int y)   {return (LL)x*y%MOD;}
int dec (int x,int y)   {x=x-y;return x<0?x+MOD:x;}
int Pow (int x,int y)
{
	if (y==1) return x;
	int lalal=Pow(x,y>>1);
	lalal=mul(lalal,lalal);
	if (y&1) lalal=mul(lalal,x);
	return lalal;
}

int JC[N],inv[N];
void Init (int n)
{
	JC[0]=1;for (int u=1;u<=n;u++) JC[u]=mul(JC[u-1],u);
	inv[n]=Pow(JC[n],MOD-2);
	for (int u=n;u>=1;u--) inv[u-1]=mul(inv[u],u);
}
int C (int x,int y)
{
	if (x<y) return 0;
	return mul(JC[x],mul(inv[y],inv[x-y]));
}
int solve (int x)
{
	for (int u=2;u*u<=x;u++)
	{
		while (x%(u*u)==0) x=x/u/u;
	}
	return x;
}
int n,a[N];
int b[N],nn=0;
int f[N][N];
int main()
{
	Init(300);
	scanf("%d",&n);
	for (int u=1;u<=n;u++) 
	{
		scanf("%d",&a[u]);
		a[u]=solve(a[u]);
	}
	sort(a+1,a+1+n);
	for (int u=1;u<=n;u++)
	{
		int i=u;
		while (a[i+1]==a[u]) i++;
		b[++nn]=(i-u+1);
		u=i;
	}
	//for (int u=1;u<=nn;u++) printf("%d ",b[u]);printf("\n");
	memset(f,0,sizeof(f));
	int sum=b[1];
	f[1][b[1]-1]=1;
	for (int u=2;u<=nn;u++)
	{
		for (int j=0;j<=sum-1;j++)//
		{
			if (f[u-1][j]==0) continue;
			for (int i=1;i<=b[u];i++)//
			{
			
				for (int k=0;k<=min(i,j);k++)//
				{
					int l=(b[u]-1)-(i-1);//
					int g=j-k+l;
					int h=C(b[u]-1,i-1);
					int jj=sum+1-j;
					h=mul(h,mul(C(jj,i-k),C(j,k)));
					f[u][g]=add(f[u][g],mul(h,f[u-1][j]));
				}
			}
		}
		sum=sum+b[u];
	}
	int ans=f[nn][0];
	for (int u=1;u<=nn;u++) ans=mul(ans,JC[b[u]]);
	printf("%d\n",ans);
	return 0;
}