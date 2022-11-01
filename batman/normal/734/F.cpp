#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)201*1000)
#define K ((ll)32)

ll n,a[N],b[N],c[N],cnt[K],sum;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
	for(int i=0;i<n;i++)cin>>b[i],sum+=b[i];
	if(sum%(2*n))return cout<<-1,0;
	sum/=2*n;
	for(int i=0;i<n;i++)
	{
		ll ex=(a[i]+b[i])-sum;
		if(ex<0 || ex%n)return cout<<-1,0;
		c[i]=((a[i]+b[i])-sum)/n;
		for(int j=0;j<K;j++)cnt[j]+=((c[i]&(1<<j))!=0);
	}
	for(int i=0;i<n;i++)
	{
		ll ex=0;
		for(int j=0;j<K;j++)
			if((c[i]&(1<<j)))
				ex+=(1LL<<j)*cnt[j];
		if(ex!=a[i])return cout<<-1,0;
	}
	for(int i=0;i<n;i++)cout<<c[i]<<" ";
	return 0;
}