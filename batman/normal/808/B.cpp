#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)1e18)

ll n,k,a[N];
ld ans;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
		if(i>=k)ans+=a[i]-a[i-k];
	}
	ans/=(ld)n-k+1;
	cout<<fixed<<setprecision(16)<<ans<<"\n";
	return 0;
}