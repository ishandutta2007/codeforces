#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define INF ((ll)1e14)
#define N (301*1000)

ll n,s,maxi;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		ll f,t;
		cin>>f>>t;
		maxi=max(maxi,t-(s-f));
	}
	cout<<maxi+s;
	
	return 0;
}