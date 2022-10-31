#include<bits/stdc++.h>
using namespace std;
const int N=200005,E=262144;
const int M=1000000007;
int n,t,i,a[N],b[N];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int mx;
	mx=b[1]=a[1];
	for(i=2;i<=n;++i)
	{
		b[i]=mx+a[i];
		mx=max(mx,mx+a[i]);
	}
	for(i=1;i<=n;++i)
		printf("%d ",b[i]);
}