#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
long long dd(long long xx)
{
	if(xx%2==1)return (xx+1)/2;
	return xx/2;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),b[i]=a[i]-a[i-1];
	long long nn=b[1];
	for(int i=2;i<=n;i++)if(b[i]>0)nn+=b[i];
	printf("%lld\n",dd(nn));
	int q;
	cin>>q;
	while(q--)
	{
		int l,r,s;
		scanf("%d%d%d",&l,&r,&s);
		nn-=b[1];
		if(l>1&&b[l]>0)nn-=b[l];
		if(r<n&&b[r+1]>0)nn-=b[r+1];
		b[l]+=s,b[r+1]-=s;
		if(l>1&&b[l]>0)nn+=b[l];
		if(r<n&&b[r+1]>0)nn+=b[r+1];
		nn+=b[1];
		printf("%lld\n",dd(nn));
	}
	return 0;
}