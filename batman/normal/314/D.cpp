#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N ((ll)101*1000)
#define INF ((ll)2e9+100)

ll n,pre_min[N],pre_max[N],suf_min[N],suf_max[N];
pair <ll,ll> a[N];

bool check(ld x)
{
	x*=2;
	for(int i=1,j=1;i<=n;i++)
	{
		while(j<=n && (ld)a[j].first-a[i].first<=x)j++;
		if((ld)max(pre_max[i-1],suf_max[j])-min(pre_min[i-1],suf_min[j])<=x)return 1;
	}
	return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i].first>>a[i].second;
    	a[i].first+=a[i].second;a[i].second-=a[i].first-a[i].second;
	}
	sort(a+1,a+n+1);
	pre_min[0]=suf_min[n+1]=INF;
	pre_max[0]=suf_max[n+1]=-INF;
	for(int i=1;i<=n;i++)pre_min[i]=min(pre_min[i-1],a[i].second),pre_max[i]=max(pre_max[i-1],a[i].second);
	for(int i=n;i>0;i--)suf_min[i]=min(suf_min[i+1],a[i].second),suf_max[i]=max(suf_max[i+1],a[i].second);
	ld l=0,r=INF;
	for(int i=0;i<200;i++)
	{
		ld mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<fixed<<setprecision(15)<<r;
	return 0;
}