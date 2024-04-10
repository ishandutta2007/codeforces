#include <bits/stdc++.h>
using namespace std;
#define ll int
const ll N=101*1000;

ll n,m,fen[N],fen_[N],last_seen[N],ans[N];
vector <ll> a[N],good[N],bad[N];
vector <pair<ll,ll> > sg[N];
bool mark[N];

void update(ll x,ll num){for(;x<=n;x+=x&-x)fen[x]+=num;}
void update_(ll x){for(;x<=n;x+=x&-x)fen_[x]++;}
ll query(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}
ll query_(ll x){ll res=0;for(;x>0;x-=x&-x)res+=fen_[x];return res;}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		ll ex;
		cin>>ex;
		a[ex].push_back(i);
	}
	for(int i=1;i<N;i++)
	{
		if((ll)a[i].size()==0)continue;
		for(int l=1,j=0;j<a[i].size();j++)bad[a[i][j]-1].push_back(l),l=a[i][j]+1;
		bad[n].push_back(a[i][(ll)a[i].size()-1]+1);
		ll l=1;
		for(int j=2;j<a[i].size();j++)
		{
			if(a[i][j]-a[i][j-1]==a[i][j-1]-a[i][j-2])continue;
			good[a[i][j]-1].push_back(l);
			bad[a[i][j]-1].push_back(a[i][j-1]+1);bad[a[i][j-1]-1].push_back(a[i][j-2]+1);
			l=a[i][j-2]+1;
		}
		good[n].push_back(l);
		for(int j=1;j<a[i].size();j++)last_seen[a[i][j]]=a[i][j-1];
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		ll l,r;
		cin>>l>>r;
		sg[r].push_back({l,i});
	}
	for(int i=n;i>0;i--)
	{
		for(int j=0;j<good[i].size();j++)update(good[i][j],1);
		for(int j=0;j<bad[i].size();j++)update_(bad[i][j]);
		for(int j=0;j<sg[i].size();j++)if(query(sg[i][j].first)>query_(sg[i][j].first))mark[sg[i][j].second]=1;
	}
	for(int i=0;i<N;i++)fen[i]=0;
	for(int i=1;i<=n;i++)
	{
		update(i,1);if(last_seen[i]!=0)update(last_seen[i],-1);
		for(int j=0;j<sg[i].size();j++)ans[sg[i][j].second]=query(i)-query(sg[i][j].first-1)+1-mark[sg[i][j].second];
	}
	for(int i=0;i<m;i++)cout<<ans[i]<<"\n";
  	return 0;
}