#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const long double PI=3.141592653589793238462643383279;
const int N=500005,M=1000000007;
int n,a[105][105],y[105],k,l[105],r[105],i,j,x[35],b[105];
void Guass()
{
	int i,j,m;
	for(i=1;i<=k&&i<=30;++i)
	{
		for(j=i;j<=k;++j)
			if(a[j][i]!=0)
			{
				swap(a[i],a[j]);
				break;
			}
		if(a[i][i])
		{
			for(j=i+1;j<=k;++j)
			{
				int t=a[j][i]*a[i][i];
				for(m=i;m<=30;++m)
					a[j][m]=a[j][m]-t*a[i][m];
				y[j]=y[j]-y[i]*t;
			}
		}
	}
}
int num(int x)
{
	int ans=0;
	while(x)
	{
		x-=-x&x;
		++ans;
	}
	return ans;
}
void dfs(int i)
{
	if(i==0)
	{
		int ans=0;
		for(i=1;i<=30;++i)
			ans|=(x[i]<<(i-1));
		for(i=1;i<=n;++i)
			if(num(b[i]^ans)!=num(b[1]^ans))
				break;
		if(i>n)
		{
			cout<<ans;
			exit(0);
		}
		return;
	}
	bool pp=true;
	int j;
	for(j=1;j<=k;++j)
		if(a[j][i]!=0)
			pp=false;
	if(pp)
	{
		x[i]=0;
		dfs(i-1);
		return;
	}
	for(j=1;j<=k;++j)
	{
		if(a[j][i]==1)
			--r[j];
		if(a[j][i]==-1)
			++l[j];
	}
	bool flag=true;
	for(j=1;j<=k;++j)
		if(l[j]>y[j]||r[j]<y[j])
			flag=false;
	x[i]=0;
	if(flag)
		dfs(i-1);
	for(j=1;j<=k;++j)
	{
		if(a[j][i]==1)
		{
			++r[j];
			++l[j];
		}
		if(a[j][i]==-1)
		{
			--l[j];
			--r[j];
		}
	}
	flag=true;
	for(j=1;j<=k;++j)
		if(l[j]>y[j]||r[j]<y[j])
			flag=false;
	x[i]=1;
	if(flag)
		dfs(i-1);
	for(j=1;j<=k;++j)
	{
		if(a[j][i]==1)
			--l[j];
		if(a[j][i]==-1)
			++r[j];
	}
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&b[i]);
	for(i=2;i<=n;++i)
	{
		++k;
		for(j=0;j<30;++j)
			if(((b[i]^b[1])>>j)&1)
			{
				if((b[i]>>j)&1)
					a[k][j+1]=-1;
				else
					a[k][j+1]=1;
			}
		y[k]=num(b[1])-num(b[i]);
		if(y[k]%2)
		{
			puts("-1");
			return 0;
		}
		y[k]/=2;
	}
	//Guass();
	for(i=1;i<=k;++i)
	{
		for(j=1;j<=30;++j)
		{
			if(a[i][j]==1)
				++r[i];
			if(a[i][j]==-1)
				--l[i];
		}
	}
	for(i=1;i<=k;++i)
		if(l[i]>y[i]||r[i]<y[i])
		{
			puts("-1");
			return 0;
		}
	/*for(i=k;i>=1;--i)
		if(l[i]==0&&r[i]==0)
		{
			swap(a[i],a[k]);
			swap(l[i],l[k]);
			swap(r[i],r[k]);
			swap(y[i],y[k]);
			--k;
		}*/
	dfs(30);
	puts("-1");
}