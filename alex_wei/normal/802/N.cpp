#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair <ll,ll>
#define fi first
#define se second

const int N=5e5+5;

ll n,k,a[N],b[N],ans;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	ll l=0,r=2e9;
	while(l<r){
		priority_queue <pll,vector<pll>,greater<pll> > q;
		ll mid=l+r>>1,num=0,sum=0;
		for(int i=1;i<=n;i++){
			q.push({a[i]-mid,0}); pll t=q.top();
			if(t.fi+b[i]<=0)num+=!t.se,sum+=t.fi+b[i],q.pop(),q.push({-b[i],1});
		} if(num>=k)r=mid,ans=sum+k*mid;
		else l=mid+1;
	} cout<<ans<<endl;
	return 0;
}