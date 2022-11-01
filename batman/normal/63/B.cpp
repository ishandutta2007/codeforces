#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((int)301*1000)
#define INF ((ll)2e9+100)
#define MOD ((ll)1e9+7)
ll tavan(ll x,ll y){ll res=1;while(y){res*=y%2?x:1;res%=MOD;x*=x;x%=MOD;y/=2;}return res;}

ll n,k,a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int t=0;;t++)
	{
		bool flg=1;
		for(int i=0;i<n;i++)if(a[i]!=k)flg=0;
		if(flg)return cout<<t,0;
		for(int i=0;i<n-1;i++)if(a[i]!=a[i+1])a[i]++;
		if(a[n-1]!=k)a[n-1]++;
		sort(a,a+n);
	}
	return 0;
}