#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300005;
int n,tt,ans,a[N],l[N],r[N];
struct st{int l,r;}p[N];
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);tt=0;ans=n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)l[i]=n+1,r[i]=0;
		for(int i=1;i<=n;i++)l[a[i]]=min(l[a[i]],i),r[a[i]]=max(r[a[i]],i);
		for(int i=1;i<=n;i++)if(r[i])p[++tt]=(st){l[i],r[i]};
		for(int i=1,j=1;i<=tt;i=j+1)
		{
			for(j=i;j<tt&&p[j].r<p[j+1].l;j++);
			ans=min(ans,tt-(j-i+1));
		}
		printf("%d\n",ans);
	}
	return 0;
}