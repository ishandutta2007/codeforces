#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (2020)
#define INF ((ll)1e14)
#define MOD ((ll)1e9+7)

ll n,a[N],m,b[N],s[2],ans;
pair <ll,ll> res[2];
set <pair<ll,pair<ll,ll> > > st;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],s[0]+=a[i];
	cin>>m;
	for(int i=1;i<=m;i++)cin>>b[i],s[1]+=b[i];
	ans=abs(s[0]-s[1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			ll x=b[j]-a[i];
			if(abs(s[0]+x-(s[1]-x))<ans)
				ans=abs(s[0]+x-(s[1]-x)),res[0]={i,j};
		}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			st.insert({a[i]+a[j],{i,j}});
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
		{
			ll x=s[0]-s[1],sum=b[i]+b[j];
			set <pair<ll,pair<ll,ll> > >::iterator it=st.lower_bound({sum+x/2,{-1,-1}});
			if(it!=st.end())
			{
				ll dif=2*abs(it->first-sum);
				if(abs(abs(s[0]-s[1])-dif)<ans)
					ans=abs(abs(s[0]-s[1])-dif),res[0]={it->second.first,i},res[1]={it->second.second,j};	
			}
			if(it!=st.begin())
			{
				it--;
				ll dif=2*abs(it->first-sum);
				if(abs(abs(s[0]-s[1])-dif)<ans)
					ans=abs(abs(s[0]-s[1])-dif),res[0]={it->second.first,i},res[1]={it->second.second,j};
			}
		}
	cout<<ans<<"\n";
	if(res[0].first==0 && res[1].first==0)return cout<<0,0;	
	if(res[1].first==0)return cout<<"1\n"<<res[0].first<<" "<<res[0].second,0;
	cout<<"2\n"<<res[0].first<<" "<<res[0].second<<"\n"<<res[1].first<<" "<<res[1].second;
    return 0;
}