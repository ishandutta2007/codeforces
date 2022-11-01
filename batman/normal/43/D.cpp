#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define PI ((ld)3.141592653589793)
#define N (301*1000)

ll n,m,num[3];
bool swaped;

void out(ll x,ll y)
{
	if(swaped)cout<<y<<" "<<x<<"\n";
	else cout<<x<<" "<<y<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	if(n==1 && m>=3)
	{
		cout<<1<<"\n"<<1<<" "<<m<<" "<<1<<" "<<1<<"\n";
		for(int i=1;i<=m;i++)out(1,i);
		out(1,1);
		return 0;
	}
	if(m==1 && n>=3)
	{
		cout<<1<<"\n"<<n<<" "<<1<<" "<<1<<" "<<1<<"\n";
		for(int i=1;i<=n;i++)out(i,1);
		out(1,1);
		return 0;
	}
	if(n%2==0 || m%2==0)
	{
		cout<<0<<"\n";
		if(n%2)swap(n,m),swaped=1;
		for(int i=1;i<=m;i++)out(1,i);
		for(int i=2;i<=n;i++)out(i,m);
		for(int i=m-1;i>=1;i--)out(n,i);
		for(int i=n-1;i>=2;i--)
		{
			if(i%2)for(int j=1;j<=m-1;j++)out(i,j);
			else for(int j=m-1;j>=1;j--)out(i,j);
		}
		out(1,1);
		return 0;
	}
	
	cout<<1<<"\n"<<n<<" 1 "<<n-1<<" "<<m-1<<"\n";
	for(int i=1;i<=m;i++)out(1,i);
	for(int i=2;i<=n;i++)out(i,m);
	for(int i=m-1;i>=1;i--)out(n,i);
	for(int i=n-1;i>=2;i--)
	{
		if(i%2)for(int j=1;j<=m-1;j++)out(i,j);
		else for(int j=m-1;j>=1;j--)out(i,j);
	}
	out(1,1);
	return 0;
}