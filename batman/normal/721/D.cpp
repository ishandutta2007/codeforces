#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N ((ll)401*1000)
#define INF ((ll)1e9+10)
#define MOD ((ll)1e9+7)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,k,x,a[N],mini=-1,num;


void solve()
{
	set <pair<ll,ll> > s;
	for(int i=0;i<n;i++)
		s.insert({abs(a[i]),i});
	for(int i=0;i<k;i++)
	{
		ll id=s.begin()->second;s.erase(s.begin());
		if(a[id]<0)a[id]-=x,s.insert({abs(a[id]),id});
		else a[id]+=x,s.insert({abs(a[id]),id});
	}
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>x;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)num++;
		if(mini==-1 || abs(a[mini])>abs(a[i]))mini=i;
	}
	if(num%2==1)solve();
	if(a[mini]>=0)
	{
		if(a[mini]-k*x>=0)
		{
			a[mini]-=k*x;
			for(int i=0;i<n;i++)cout<<a[i]<<" ";
			return 0;
		}
		k-=a[mini]/x+1;
		a[mini]-=(a[mini]/x+1)*x;
	}
	else if(a[mini]<0)
	{
		a[mini]*=-1;
		if(a[mini]-k*x>=0)
		{
			a[mini]-=k*x;
			a[mini]*=-1;
			for(int i=0;i<n;i++)cout<<a[i]<<" ";
			return 0;
		}
		k-=a[mini]/x+1;
		a[mini]-=(a[mini]/x+1)*x;
		a[mini]*=-1;
	}
	solve();
	return 0;
}