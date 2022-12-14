#include<bits/stdc++.h>
using namespace std;

int fuck[4040404],dep[4040404];
int a[4040404];

vector<int> anss;

int h,g;
void f(int x)
{
	int l=x*2,r=x*2+1;
	if(a[l]==0&&a[r]==0)
		a[x]=0;
	else
	{
		if(a[l]>a[r])
		{
			a[x]=a[l];
			f(l);
		}
		else
		{
			a[x]=a[r];
			f(r);
		}
	}
	
	if(a[l]==0&&a[r]==0&&dep[x]<=g)
		fuck[x]=1;
	else if(a[l]>a[r]&&fuck[l]==1)
		fuck[x]=1;
	else if(a[l]<a[r]&&fuck[r]==1)
		fuck[x]=1;
	
}

int main()
{
	dep[1]=1;
	for(int i=2;i<(1<<21);i++)
		dep[i]=dep[i/2]+1;
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&h,&g);
		int n=(1<<h)-1;
		for(int i=1;i<=n*2+1;i++)
			a[i]=fuck[i]=0; 
		
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		anss.clear();
		
		for(int i=1;i<=n;i++)
		if(a[i]>0)
		{
			while(a[i]>0&&fuck[i]==0)
			{
				f(i);
				anss.push_back(i);
			}
		}
		long long ans=0;
		for(int i=1;i<(1<<g);i++)
			ans+=a[i];
		printf("%lld\n",ans);
		for(int x:anss)
			printf("%d ",x);
		puts("");
	}
	return 0;
}