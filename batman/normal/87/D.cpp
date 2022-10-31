#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (101*1000)
#define K (60)
#define INF ((ll)1e15)

ll n,m,ans[N],dp_down[N],all_sz;
vector <pair<pair<ll,ll>,pair<ll,ll> > > ed;
vector <pair<ll,pair<ll,bool> > > e[N];
bool mark[N];
ll par[N];

ll root(int x){if(par[x]<0)return x;return par[x]=root(par[x]);}
void merge(ll x,ll y){x=root(x);y=root(y);par[y]+=par[x];par[x]=y;}

void dfs(ll x)
{
    mark[x]=1;all_sz+=-par[x];
    //cout<<x<<" "<<par[x]<<"\n";
    for(int i=0;i<e[x].size();i++)
    if(e[x][i].second.second)
    {
        if(!mark[e[x][i].first])
            dfs(e[x][i].first);
    }
    mark[x]=0;
}

void dfs2(ll x)
{
    //cout<<x<<" "<<par[x]<<"\n";
    mark[x]=1;
    dp_down[x]=-par[x];
    for(int i=0;i<e[x].size();i++)
    if(e[x][i].second.second)
    {
        if(!mark[e[x][i].first])
        {
            //cout<<par[e[x][i].first]<<"\n";
            dfs2(e[x][i].first);
            dp_down[x]+=dp_down[e[x][i].first];
            ans[e[x][i].second.first]=dp_down[e[x][i].first]*(all_sz-dp_down[e[x][i].first]);
        }
        e[x][i].second.second=0;
    }
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
	for(int i=1;i<=n;i++)par[i]=-1;
	for(int i=0;i<n-1;i++)
	{
		ll v,u,w;
		cin>>v>>u>>w;
		ed.push_back({{w,i},{u,v}});
	}
	sort(ed.begin(),ed.end());
	ll i=0;
	while(i<ed.size())
	{
		vector <ll> vec;
		ll j=i;
		while(j<ed.size() && ed[j].first.first==ed[i].first.first)
		{
			ll v=root(ed[j].second.first),u=root(ed[j].second.second);
			vec.push_back(v);vec.push_back(u);
			//cout<<u<<" "<<v<<"\n";
			e[u].push_back({v,{ed[j].first.second,1}});
			e[v].push_back({u,{ed[j].first.second,1}});
			j++;
		}
		for(int i=0;i<vec.size();i++)
            if(!mark[vec[i]])
            {
                all_sz=0;
                //cout<<vec[i]<<" ";
                dfs(vec[i]);
                //cout<<vec[i]<<" "<<all_sz<<"\n";
                dfs2(vec[i]);
            }
		j=i;
		while(j<ed.size() && ed[j].first.first==ed[i].first.first)
		{
			ll v=root(ed[j].second.first),u=root(ed[j].second.second);
			merge(u,v);
			//cout<<par[u]<<" "<<par[v]<<"\n";
			dp_down[v]=dp_down[u]=mark[v]=mark[u]=0;
			j++;
		}
		i=j;
	}
	ll maxi=0,num=0;
	for(int i=0;i<n-1;i++)
    {
        //cout<<ans[i]<<"\n";
        if(ans[i]>maxi)maxi=ans[i],num=1;
        else if(ans[i]==maxi)num++;
    }

    cout<<maxi*2<<" "<<num<<"\n";
    for(int i=0;i<n-1;i++)
        if(ans[i]==maxi)
            cout<<i+1<<" ";
    return 0;
}