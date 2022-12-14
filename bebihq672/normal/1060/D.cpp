#include<bits/stdc++.h>
using namespace std;
int l[101010],r[101010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++)
		ans+=max(l[i],r[i]);
	ans+=n;
	printf("%I64d\n",ans);
	return 0;
}