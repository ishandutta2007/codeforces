#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define N ((ll)301*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e18)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,a[N],ans;

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n;
	ll cnt=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(!i){cnt++;continue;}
		if(a[i]==a[i-1])cnt++;
		else ans+=cnt*(cnt-1)/2+cnt,cnt=1;
	}
	ans+=cnt*(cnt-1)/2+cnt;
	cout<<ans;
	return 0;
}