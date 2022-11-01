#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)201*1000)
#define INF ((ll)2e9)

int n,a[N],maxi[N],b[N],gcd[N],cnt[N];
ll ans;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++)gcd[i]=__gcd(i,n);
	for(int i=1;i<n;i++)
	{
		if(n%i!=0)continue;
		for(int j=0;j<i;j++)maxi[j]=0;
		for(int j=0;j<n;j++)maxi[j%i]=max(maxi[j%i],a[j]),b[j]=0;
		for(int j=1;j<=n;j++)cnt[j]=cnt[j-1]+(gcd[j]==i);
		for(int j=0,now=0;j<2*n;j++)
		{
			if(maxi[j%i]==a[j%n])
			{
				now++;
				b[j%n]=max(b[j%n],now);
				continue;
			}
			now=0;
		}
		for(int j=0;j<n;j++)ans+=cnt[min(b[j],n)];
	}
	cout<<ans;
	return 0;
}