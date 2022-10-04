#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
ll n,m,x[7],y[7];

ll cw(ll x,ll y)//black
	{return (ll)x*y/2;}
ll cb(ll x,ll y)//white
	{return (ll)x*y-(ll)x*y/2;}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=4;i++)
		cin>>x[i]>>y[i];
	ll cur=cw(x[2],y[2])-cw(x[1]-1,y[2])-cw(x[2],y[1]-1)+cw(x[1]-1,y[1]-1);
	ll ucr=cb(x[4],y[4])-cb(x[3]-1,y[4])-cb(x[4],y[3]-1)+cb(x[3]-1,y[3]-1);
	ll ans=n*m/2-cur+ucr;
	x[3]=max(x[3],x[1]);y[3]=max(y[3],y[1]);
	x[4]=min(x[4],x[2]);y[4]=min(y[4],y[2]);
	if(x[3]<=x[4] && y[3]<=y[4])
		ans+=cw(x[4],y[4])-cw(x[3]-1,y[4])-
		cw(x[4],y[3]-1)+cw(x[3]-1,y[3]-1);
	cout<<(ll)n*m-ans<<" "<<ans<<endl;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)solve();
    return 0;
}