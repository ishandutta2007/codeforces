#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,m,a[N],l[N];
bool mark[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=n-1;i>=0;i--)
	{
		l[i]=l[i+1];
		if(!mark[a[i]])mark[a[i]]=1,l[i]++;
	}
	while(m--)
	{
		ll x;
		cin>>x;
		cout<<l[x-1]<<"\n";
	}
    return 0;
}