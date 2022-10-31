#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)3300)
#define INF ((ll)1e18)
#define MOD ((ll)1e9+7)

ll n,m,a[N],num[N],m2;
vector <ll> gp[N];

void _do()
{
	for(int i=1;i<=n;i++)gp[i].clear();
	memset(num,0,sizeof num);m2=0;
	for(int i=1;i<=n;i++)
		if(!num[i])
		{
			m2++;
			num[i]=i;
			gp[i].push_back(i);
			ll x=a[i];
			while(x!=i)num[x]=i,gp[i].push_back(x),x=a[x];
		}
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;m=n-m;
	_do();
	cout<<abs(m2-m)<<"\n";
	if(m2>m)
	{
		ll p=m2-m;
		for(int i=2;p && i<=n;i++)
			if(gp[i].size())
			{
				p--;
				cout<<1<<" "<<i<<" ";
			}
		return 0 ;
	}
	ll p=m-m2;
	while(p)
	{
		for(int i=1;i<=n && p;i++)
			if(gp[i].size()>1)
			{
				ll mini=1;
				for(int j=2;j<gp[i].size();j++)
					if(gp[i][j]<gp[i][mini])
						mini=j;
				cout<<i<<" "<<gp[i][mini]<<" ";p--;
				a[gp[i][mini]]=a[i];
				a[i]=gp[i][(mini+1)%((ll)gp[i].size())];
				break;	
			}
		_do();
	}
	return 0;
}