#include<bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
//#define double long double
const int N=105;
int X[N],n,t,V[N];
ll a[N],B[N][N],x,y,z,ans,v;
void work(ll ab,ll b,int k)
{
	if(ab<b*b)
		return;
	if(k==n+1)
	{
		ll a=ab/b,c=v/ab,tmp=a*c+ab+b*c;
		if(tmp<ans)
		{
			ans=tmp;
			x=a;
			y=b;
			z=c;
		}
		return;
	}
	int t=X[k]-V[k];
	for(int i=t;i>=0;i--)
		work(ab,b*B[k][i],k+1);
}
void dfs(ll s,int k)
{
	if (v/s<s*s)
		return;
	if (k==n+1)
	{
		ll ss=v/s;
		if (ss+2*sqrt((double)v*s)<=ans)
			work(ss,1,1);
		return;
	}
	for (int i=X[k];i>=0;--i)
	{
		V[k]=i;
		dfs(s*B[k][i],k+1);
	}
}
signed main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		v=1;
		for (int i=1;i<=n;++i)
		{
			scanf("%lld%d",&a[i],&X[i]);
			B[i][0]=1;
			for (int j=1;j<=X[i];++j)
				B[i][j]=B[i][j-1]*a[i];
			v*=B[i][X[i]];
		}
		x=v;
		y=1;
		z=1;
		ans=2*v+1;
		dfs(1,1);
		ans*=2;
		cout<<ans<<' '<<x<<' '<<y<<' '<<z<<'\n';
	}
	return 0;
}