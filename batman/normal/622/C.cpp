#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (301*1000)
#define K (1001*1000)

ll n,m,a[N],last[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0){last[i]=-1;continue;}
		if(a[i]!=a[i-1])last[i]=i-1;
		else last[i]=last[i-1];
	}
	while(m--)
	{
		ll l,r,x;
		cin>>l>>r>>x;
		l--;r--;
		if(a[r]!=x)cout<<r+1<<"\n";
		else if(last[r]>=l)cout<<last[r]+1<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}