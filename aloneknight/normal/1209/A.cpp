#include<bits/stdc++.h>
using namespace std;
int n,cc,a[105],vis[105];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)if(!vis[i])
	{
		for(int j=i;j<=n;j++)if(a[j]%a[i]==0)vis[j]=1;
		cc++;
	}
	printf("%d\n",cc);
	return 0;
}