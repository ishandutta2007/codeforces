#include <bits/stdc++.h>
using namespace std;
#define IB ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ld long double
#define N (301*1000)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)

ll n,m,a[N],ans;

int main()
{
	IB
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2*m;j++)
		{
			cin>>a[j];
			if(j%2==1)
				if(a[j] || a[j-1])
					ans++;
		}
	}
	cout<<ans;
	
    return 0;
}