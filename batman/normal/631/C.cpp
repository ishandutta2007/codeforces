#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (201*1000)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

ll n,m,a[N],ans[N];
deque <pair<ll,bool> > d;
deque <ll> d2;

int main()
{ 
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)
    {
    	ll t,r;
    	cin>>t>>r;
    	r--;
    	while(d.size() && d.back().first<r)d.pop_back();
    	d.push_back({r,t-1});
	}
	ll x=d[0].first,q=n-1;
	for(;q>x;q--)ans[q]=a[q];
	sort(a,a+x+1);
	for(int i=0;i<=x;i++)d2.push_back(a[i]);
	bool p=d[0].second;
	for(int i=1;i<d.size();i++)
	{
		if(p)
		{
			ll ex=d[i-1].first-d[i].first;
			for(int j=0;j<ex;j++,q--)ans[q]=d2.front(),d2.pop_front();
		}
		else
		{
			ll ex=d[i-1].first-d[i].first;
			for(int j=0;j<ex;j++,q--)ans[q]=d2.back(),d2.pop_back();
		}
		p=d[i].second;
	}
	if(p)
		{
			ll ex=d[(ll)d.size()-1].first;
			for(int j=0;j<=ex;j++,q--)ans[q]=d2.front(),d2.pop_front();
		}
		else
		{
			ll ex=d[(ll)d.size()-1].first;
			for(int j=0;j<=ex;j++,q--)ans[q]=d2.back(),d2.pop_back();
		}
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
    return 0;
}