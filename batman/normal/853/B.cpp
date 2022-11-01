#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define K ((ll)1001*1000)
#define INF ((ll)1e18)

int n,m,k;
ll all;
int cnt_come,cnt_go;
int min_go[N];
multiset <int> min_come[N];
bool go[N],come[N];
vector <pair<int,int> > v1[K],v2[K];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		int t,v,u,c;
		cin>>t>>v>>u>>c;
		if(u==0)
			v1[t].push_back({v,c});
		else
			v2[t].push_back({u,c});
	}
	for(int i=K-1;i>k;i--)
	{
		for(auto u:v2[i])
		{
			min_come[u.first].insert(u.second);
			if(!come[u.first])come[u.first]=1,cnt_come++;
		}
	}
	ll ans=INF;
	if(cnt_come!=n)return cout<<"-1\n",0;
	for(int i=1;i<=n;i++)all+=*min_come[i].begin();
	for(int i=2;i<=K-k;i++)
	{
		int j=i+k-1;
		for(auto u:v1[i-1])
		{
			if(!go[u.first])
			{
				go[u.first]=1;cnt_go++;
				min_go[u.first]=u.second;
				all+=u.second;
				continue;
			}
			all-=min_go[u.first];
			min_go[u.first]=min(min_go[u.first],u.second);
			all+=min_go[u.first];
		}
		for(auto u:v2[j])
		{
			all-=*min_come[u.first].begin();
			min_come[u.first].erase(min_come[u.first].find(u.second));
			if(!min_come[u.first].size())
			{
				if(ans>(ll)1e15)return cout<<"-1\n",0;
				return cout<<ans<<"\n",0;
			}
			all+=*min_come[u.first].begin();
		}
		if(cnt_go==n)ans=min(ans,all);
	}
	cout<<ans<<"\n";
	return 0;
}