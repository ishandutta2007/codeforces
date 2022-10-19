#include<bits/stdc++.h>
using namespace std;
int a[10005],t[1000005];
int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n,tot=0;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(a[i]!=a[j])
			t[++tot]=max(a[i],a[j])-min(a[i],a[j]);
		sort(t+1,t+tot+1);
		tot=unique(t+1,t+tot+1)-t-1;
		printf("%d\n",tot);
	}
	return 0;
}