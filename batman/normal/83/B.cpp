#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define N ((ll)301*1000)
#define MOD ((ll)1e9+7)
#define INF ((ll)1e18)
ll tavan(ll a,ll b,ll mod=MOD){ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

ll n,k,a[N],num,mark[N],last;
map <ll,vector<ll> > mp;

void solve()
{
	vector <ll> v;
	for(int i=0;i<n;i++)if(!mark[i])v.push_back(i);
	ll k2=k%num;
	for(int i=k2;i<num;i++)cout<<v[i]+1<<" ";
	for(int i=0;i<k2;i++)
		if(!(k/num==a[v[i]]-last-1))
			cout<<v[i]+1<<" ";
	exit(0);
}

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	cin>>n>>k;
	num=n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		mp[a[i]].push_back(i);
	}
	for(auto x:mp)
	{
		vector <ll> v=x.second;
		if(k<num*(x.first-last))solve();
		k-=num*(x.first-last);
		last=x.first;num-=(ll)v.size();
		for(auto u:v)mark[u]=1;
	}
	if(k>0)cout<<-1;
	return 0;
}