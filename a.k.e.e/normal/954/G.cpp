#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=500005;

int n,r,a[MAXN];
ll k;
ll c[MAXN];
bool check(ll mid)
{
	for(int i=1;i<=n;i++)
		c[i]=a[i];
	ll cur=0,sum=0;
	for(int i=1;i<=r;i++)cur+=c[i];
	for(int i=1;i<=n;i++)
	{
		if(i+r<=n)cur+=c[i+r];
		if(i-r-1>0)cur-=c[i-r-1];
		if(cur<mid)
		{
			sum+=mid-cur;
			if(sum>k)return 0;
			c[min(n,i+r)]+=mid-cur;
			cur=mid;
		}
	}
	return 1;
}

int main()
{
    cin>>n>>r>>k;
    ll L=0,R=k,mid,ans=0;
    for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		R+=a[i];
	}
    while(L<=R)
    {
    	mid=(L+R)>>1;
    	if(check(mid))ans=mid,L=mid+1;
    	else R=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}