#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)301*1000)
#define INF ((ll)2e9)
#define MOD ((ll)1e9+7)

ll n,m,mini=INF;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   	cin>>n>>m;
   	for(int i=0;i<m;i++)
   	{
   		ll l,r;
   		cin>>l>>r;
   		mini=min(mini,r-l+1);
	   }
	cout<<mini<<"\n";
	for(int i=1;i<=n;i++)cout<<(i-1)%mini<<" ";
   	
	return 0;
}