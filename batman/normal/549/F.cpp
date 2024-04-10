#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)301*1000)
#define K ((ll)1001*1000)
#define INF ((ll)1e18+10)

ll n,k,a[N],cnt[K],ex[N],ex_num;

ll solve(ll l,ll r)
{
	if(l>=r-1)return 0;
	ll mid=(l+r)/2,ans=solve(l,mid)+solve(mid,r);
	ll j=mid-1,maxi_i=0,sum_j=0,sum_i=0;
	for(int i=mid;i<r;i++)
	{
		maxi_i=max(maxi_i,a[i]);
		sum_i+=a[i];
		while(j>=l && maxi_i>a[j])sum_j+=a[j],cnt[sum_j%k]++,ex[ex_num++]=sum_j%k,j--;
		ans+=cnt[(((maxi_i-sum_i)%k)+k)%k];
	}
	while(ex_num)cnt[ex[ex_num-1]]=0,ex_num--;
	j=mid,sum_j=0,sum_i=0,maxi_i=0;
	for(int i=mid-1;i>=l;i--)
	{
		maxi_i=max(maxi_i,a[i]);
		sum_i+=a[i];
		while(j<r && maxi_i>=a[j])sum_j+=a[j],cnt[sum_j%k]++,ex[ex_num++]=sum_j%k,j++;
		ans+=cnt[(((maxi_i-sum_i)%k)+k)%k];
	}
	while(ex_num)cnt[ex[ex_num-1]]=0,ex_num--;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<solve(0,n);
	return 0;
}