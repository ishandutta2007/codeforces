#include<bits/stdc++.h>
using namespace std;
int a[101010];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]>a[ans+1])
			ans++;
	printf("%d\n",ans);
	return 0;
}