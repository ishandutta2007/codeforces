#include<bits/stdc++.h>
using namespace std;
const int N=3505;
int n,m,k,a[N],b[N];
int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);k=min(k,m-1);int rst=n-m;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)b[i]=max(a[i],a[i+rst]);
		int ans=0;
		for(int i=0;i<=k;i++)
		{
			int l=i+1,r=m-(k-i),res=2e9;
			for(int j=l;j<=r;j++)res=min(res,b[j]);
			ans=max(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}