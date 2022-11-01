#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e18)

ll n,pre[N],nex[N];
pair <ll,ll> a[N];
set <ll> s;
ld ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].first,a[i].second=i,nex[i]=n,pre[i]=-1;
	pre[n]=-1;s.insert(n);
	sort(a,a+n);
	for(int i=n-1;i>=0;i--)
	{
		ll id=a[i].second,x=*s.lower_bound(id);
		ld rght=0,now=1;
		for(int j=0;j<50;j++)
		{
			rght+=now*((ld)x-id);
			if(x==n)break;
			now*=(ld)1/2;
			id=x;
			x=nex[x];
		}
		ld lft=0;now=1;id=a[i].second;x=pre[*s.lower_bound(id)];
		for(int j=0;j<50;j++)
		{
			lft+=now*((ld)id-x);
			if(x==-1)break;
			now*=(ld)1/2;
			id=x;
			x=pre[x];
		}
		ans+=lft*rght*1/2*a[i].first;
		id=a[i].second;
		x=*s.lower_bound(id);
		pre[id]=pre[x];
		nex[pre[x]]=id;
		pre[x]=id;
		nex[id]=x;
		s.insert(id);
	}
	ans/=(ld)n*n;
	cout<<fixed<<setprecision(16)<<ans<<"\n";
	return 0;
}