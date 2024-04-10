#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (1111)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

ll n,m,k;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)
	{
		ll a,b;
		cin>>a>>b;
		if(a<=5 || a>=n-4 || b<=5 || b>=m-4)return cout<<"YES",0;
	}
	cout<<"NO";
    return 0;
}