#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,m,k,x,s,ps[N],ans,c[N];
pair <ll,ll> a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k>>x>>s;
	ans=n*x;
	for(int i=0;i<m;i++)cin>>a[i].second;
	for(int i=0;i<m;i++)
	{
		cin>>a[i].first;
		if(a[i].first<=s)ans=min(ans,n*a[i].second);
	}
	sort(a,a+m);
	ps[0]=a[0].second;
	for(int i=1;i<m;i++)ps[i]=min(a[i].second,ps[i-1]);
	for(int i=0;i<k;i++)cin>>c[i];
	for(int i=0;i<k;i++)
	{
		ll v,u;
		cin>>u;v=c[i];
		if(u>s)continue;
		pair <ll,ll> ex={s-u+1,0};
		ll id=lower_bound(a,a+m,ex)-a;id--;
		ans=min(ans,(n-v)*x);
		if(id>=0)ans=min(ans,(n-v)*ps[id]);
	}
	cout<<ans;
	return 0;
}