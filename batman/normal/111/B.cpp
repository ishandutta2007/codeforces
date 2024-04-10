#include <bits/stdc++.h>
using namespace std;
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)
#define N (101*1000)
#define ll long long
#define ld long double

ll n,a[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	ll x,y,ans=0;
    	cin>>x>>y;
    	for(ll j=1;j*j<=x;j++)
    		if(x%j==0)
    		{
    			if(a[j]<i-y)
    				ans++;
				if(x/j!=j && a[x/j]<i-y)
					ans++;
				a[j]=i;
				a[x/j]=i;					
			}
		cout<<ans<<"\n";	
	}
    return 0;
}