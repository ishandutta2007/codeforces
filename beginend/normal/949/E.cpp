#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200005;
const int inf=1000000000;

int n,a[N],f[20][N],ans,tot[20],A[20],top,stack[20];

void solve(int dep,int step)
{
	if (dep==19) return;
	sort(f[dep]+1,f[dep]+tot[dep]+1);
	tot[dep]=unique(f[dep]+1,f[dep]+tot[dep]+1)-f[dep]-1;
	int s1=0,s0=0;
	for (int i=1;i<=tot[dep];i++)
		if (f[dep][i]!=0&&f[dep][i]%2==0) s0++;
		else if (f[dep][i]%2!=0) s1++;
	if (!s0&&!s1)
	{
		if (step<ans)
		{
			ans=step;
			for (int i=1;i<=step;i++) A[i]=stack[i];
		}
		return;
	}
	if (!s1)
	{
		tot[dep+1]=0;
		for (int i=1;i<=tot[dep];i++)
			if (f[dep][i]/2!=0) f[dep+1][++tot[dep+1]]=f[dep][i]/2;
		solve(dep+1,step);
	}
	else
	{
		tot[dep+1]=0;stack[++top]=1<<dep;
		for (int i=1;i<=tot[dep];i++)
			if (f[dep][i]%2==0&&f[dep][i]/2!=0) f[dep+1][++tot[dep+1]]=f[dep][i]/2;
			else if (f[dep][i]%2!=0) f[dep+1][++tot[dep+1]]=(f[dep][i]-1)/2;
		solve(dep+1,step+1);top--;
		tot[dep+1]=0;stack[++top]=-(1<<dep);
		for (int i=1;i<=tot[dep];i++)
			if (f[dep][i]%2==0&&f[dep][i]/2!=0) f[dep+1][++tot[dep+1]]=f[dep][i]/2;
			else if (f[dep][i]%2!=0) f[dep+1][++tot[dep+1]]=(f[dep][i]+1)/2;
		solve(dep+1,step+1);top--;
	}
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);n=unique(a+1,a+n+1)-a-1;
	tot[0]=n;
	for (int i=1;i<=n;i++) f[0][i]=a[i];
	ans=20;solve(0,0);
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++) printf("%d ",A[i]);
	return 0;
}