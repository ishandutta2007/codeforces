#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N 5500
ll n,w,h,dp[N],ans,last[N],p=-1;
pair <pair<ll,ll>,ll> wh[N];
bool sortt(pair <pair<ll,ll>,ll> x,pair <pair<ll,ll>,ll> y)
{
	return (x.first.first+x.first.second<y.first.first+y.first.second);
}

int main()
{ 
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>w>>h;
    for(int i=0,j=1;i<n;j++,i++)
    {
    	ll x,y;
    	cin>>x>>y;	
    	if(x>w && y>h)
    		wh[i]={{x,y},j};
    	else
			n--,i--;	
    }
    sort(wh,wh+n,sortt);
    //cerr<<wh[0].first<<" "<<wh[0].second;
    for(int i=0;i<N;i++)
    	last[i]=-1,dp[i]=1;
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<i;j++)
    		if(wh[i].first.first>wh[j].first.first && wh[i].first.second>wh[j].first.second)
    			if(dp[i]<dp[j]+1)
    				dp[i]=dp[j]+1,last[i]=j;
    	if(ans<dp[i])
			ans=dp[i],p=i;	
    }
    cout<<ans<<"\n";
    ll res[N],tmp=0;
    for(int i=p;i!=-1;i=last[i])
    	res[tmp++]=wh[i].second;
    for(int i=tmp-1;i>=0;i--)
		cout<<res[i]<<" ";	
    return 0;
}