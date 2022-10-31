#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =100100;
const ll K=10100;
ifstream fin("input.txt");
ofstream fout("output.txt");

ll n,m,ans,lft,rght;
vector <ll> vec;
vector <pair<ll,pair<ll,ll> > > e[N];
bool mark[N];

void dfs(ll x)
{
	mark[x]=1;
	for(int i=0;i<e[x].size();i++)
	{
		ll v=e[x][i].first,l=e[x][i].second.first,r=e[x][i].second.second;
		if(!mark[v] && l<=lft && rght<=r)dfs(v);
	}
}

int main() 
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		ll v,u,l,r;
		cin>>v>>u>>l>>r;
		vec.push_back(l);vec.push_back(r);
		e[v].push_back({u,{l,r}});
		e[u].push_back({v,{l,r}});
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	{
		ll l=i-1,r=(ll)vec.size();
		while(l<r-1)
		{
			for(int j=1;j<=n;j++)
				mark[j]=0;
			ll mid=(l+r)/2;
			lft=vec[i];rght=vec[mid];
			dfs(1);
			if(mark[n])l=mid;
			else r=mid;
		}
		if(l!=i-1)
			ans=max(ans,vec[l]-vec[i]+1);
	}
	if(ans==0)cout<<"Nice work, Dima!";
	else cout<<ans;
	return 0;
}