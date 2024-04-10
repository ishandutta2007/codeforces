#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (5100)
#define INF ((ll)1e15)
#define MOD ((ll)1e9+7)

ll n,m,k;
vector <pair<ll,ll> > v[2][N];

int main()
{ 
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
    	ll p,a,c;
    	cin>>p>>a>>c;
    	v[p-1][a].push_back({c,i});
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(v[0][i].size()==0 && v[1][j].size()==0){cout<<"0 ";continue;}
			if(v[0][i].size()==0){cout<<v[1][j][(ll)v[1][j].size()-1].first<<" ";continue;}
			if(v[1][j].size()==0){cout<<v[0][i][(ll)v[0][i].size()-1].first<<" ";continue;}
			ll ans=v[0][i][(ll)v[0][i].size()-1].first;
			if(v[1][j][(ll)v[1][j].size()-1].second>v[0][i][(ll)v[0][i].size()-1].second)ans=v[1][j][(ll)v[1][j].size()-1].first;
			cout<<ans<<" ";
		}
		cout<<"\n";
	}
		
    return 0;
}