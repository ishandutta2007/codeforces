#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define MOD ((ll)1e9+7)
#define INF ((ll)1e9)
#define N (201*1000)

ll n,l,par[N],d[N],p[N];
vector <pair<ll,ll> > e[N],ex;
bool used[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>l;
	for(int i=0;i<n;i++)
	{
		ll x,d,t,p;
		cin>>x>>d>>t>>p;
		if(d<t)continue;
		if(x-p>=0)
			ex.push_back({x-p,i*2}),e[i*2].push_back({i*2+1,p+t});
		used[i]=1;	
		ex.push_back({x+d,i*2+1});
	}
	ex.push_back({0,2*n}),ex.push_back({l,2*n+1});
	sort(ex.begin(),ex.end());
	for(int i=0;i<(ll)ex.size()-1;i++)
		e[ex[i].second].push_back({ex[i+1].second,ex[i+1].first-ex[i].first}),e[ex[i+1].second].push_back({ex[i].second,ex[i+1].first-ex[i].first});;
	for(int i=0;i<N;i++)d[i]=INF;
	set <pair<ll,ll> > s;s.insert({0,2*n});d[2*n]=0;par[2*n]=-1;
	while(s.size())
	{
		ll x=s.begin()->second;s.erase(s.begin());
		for(int i=0;i<e[x].size();i++)
			if(d[e[x][i].first]>d[x]+e[x][i].second)
				s.erase({d[e[x][i].first],e[x][i].first}),d[e[x][i].first]=d[x]+e[x][i].second,par[e[x][i].first]=x,s.insert({d[e[x][i].first],e[x][i].first});
	}
	cout<<d[2*n+1]<<"\n";
	stack <ll> ans;
	ll x=2*n+1;
	while(par[x]!=-1)
	{
		if(par[x]==x-1 && x%2==1 && x!=2*n+1 && used[x/2])ans.push(x/2+1),x=par[par[x]];
		else x=par[x];
	}
	cout<<(ll)ans.size()<<"\n";
	while(ans.size())cout<<ans.top()<<" ",ans.pop();
	return 0;
}