#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e15)
#define N (301*1000)

ll n,a[N],p=-1;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		p+=a[i];
		p%=(n+1);	
	}
	ll ans=0;
	for(int i=1;i<=5;i++)
		if((p+i)%(n+1)!=0)
			ans++;
	cout<<ans;		
	
	
	return 0;
}