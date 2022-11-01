#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)1100)

ll n,d[N];
ll cnt=1;
vector <pair<ll,ll> > ed;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>d[i];
	for(ll l=0,r=n-1;l<=r;l++,r--)
	{
		for(int i=0;i<d[l];i++)
		{
			for(int j=cnt+1;j<=d[n-1]+1;j++)
				ed.push_back({cnt,j});
			cnt++;
		}
		for(int i=l+1;i<r;i++)d[i]-=d[l];
		while(d[n-1]+1-cnt+1>d[r-1]+1)cnt++;
	}
	cout<<ed.size()<<"\n";
	for(auto u:ed)cout<<u.first<<" "<<u.second<<"\n";
	return 0;
}