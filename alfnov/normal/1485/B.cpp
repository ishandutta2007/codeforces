#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n,q,k;
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%lld\n",0ll+a[r]-a[l]+k+1-2ll*(r-l)-2);
	}
	return 0;
}