#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define N (201*1000)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}

ll n,k,d[2][N];
bool mark[2][N];
string s[2];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>s[0]>>s[1];
	for(int i=0;i<=k+100;i++)s[0]+='-',s[1]+='-';
	queue <pair <bool,ll> > q;
	q.push({0,0});
	while(q.size())
	{
		bool p=q.front().first;
		ll x=q.front().second;
		q.pop();
		//cout<<p<<" "<<x<<" "<<d[p][x]<<"\n";
		if(x>0 && !mark[p][x-1] && s[p][x-1]=='-')
		{
			mark[p][x-1]=1;
			d[p][x-1]=d[p][x]+1;
			if(d[p][x-1]<=x-1)
				q.push({p,x-1});	
		}
		if(!mark[p][x+1] && s[p][x+1]=='-')
		{
			mark[p][x+1]=1;
			d[p][x+1]=d[p][x]+1;
			if(x+1<n)
				q.push({p,x+1});	
		}
		if(!mark[!p][x+k] && s[!p][x+k]=='-')
		{
			mark[!p][x+k]=1;
			d[!p][x+k]=d[p][x]+1;
			if(x+k<n)
				q.push({!p,x+k});
		}
	}
	for(int i=n;i<N;i++)
	{
		if(mark[0][i] && d[0][i]<=i)
			return cout<<"YES",0;
		if(mark[1][i] && d[1][i]<=i)
			return cout<<"YES",0;	
	}
	cout<<"NO";
	return 0;
}