#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)501*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,w,k,a[N],t[N],ans;
multiset <ll> s,p;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>w>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>t[i];
    for(ll i=0,j=0,time=0,res=0;i<n;i++)
    {
    	while(j<n)
    	{
    		ll now=time;
    		if((ll)s.size()<w)now+=(t[j]+1)/2;
    		else if(t[j]>(*s.begin()))now+=(t[j]+1)/2+((*s.begin())-((*s.begin())+1)/2);
    		else now+=t[j];
    		
			if(now>k)break;
    		
    		if((ll)s.size()<w)s.insert(t[j]);
    		else if(t[j]>(*s.begin()))p.insert(*s.begin()),s.erase(s.begin()),s.insert(t[j]);
    		else p.insert(t[j]);
    		
			time=now;res+=a[j];j++;
		}
		ans=max(ans,res);
		
		if(j<=i){j=i+1;continue;}
		res-=a[i];
		if(t[i]<*s.begin())p.erase(p.find(t[i])),time-=t[i];
		else 
		{
			s.erase(s.find(t[i]));
			time-=(t[i]+1)/2;
			if(p.size())
			{
				auto it=p.end();it--;
				s.insert(*it);
				time-=(*it-(*it+1)/2);
				p.erase(it);
			}
		}
	}
	cout<<ans;
    return 0;
}