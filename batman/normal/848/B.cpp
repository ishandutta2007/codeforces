#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)

ll n,w,h,g[N],x[N],t[N];
vector <pair<ll,ll> > vec[2][3*N];
pair <ll,ll> ans[N];
ll out[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>w>>h;
	for(int i=0;i<n;i++)
	{
		cin>>g[i]>>x[i]>>t[i];
		if(g[i]==1)
		{
			ans[i]={x[i],h};
			vec[0][t[i]-x[i]+N].push_back({x[i],i});
		}
		if(g[i]==2)
		{
			ans[i]={w,x[i]};
			vec[1][t[i]-x[i]+N].push_back({x[i],i});
		}
	}
	for(int i=0;i<3*N;i++)
	{
		if(!vec[0][i].size() && !vec[1][i].size())continue;
		sort(vec[0][i].begin(),vec[0][i].end());
		sort(vec[1][i].begin(),vec[1][i].end());
		if(vec[0][i].size()>vec[1][i].size())swap(vec[0][i],vec[1][i]);
		for(int j=(ll)vec[0][i].size()-1,k=0;j>=0;j--,k++)
			out[vec[0][i][j].second]=vec[1][i][k].second;
		for(int j=(ll)vec[1][i].size()-1,k=0;k<(ll)vec[0][i].size();j--,k++)
			out[vec[1][i][j].second]=vec[0][i][k].second;
		for(int j=0,k=vec[0][i].size();j<(ll)vec[1][i].size()-(ll)vec[0][i].size();j++,k++)
			out[vec[1][i][j].second]=vec[1][i][k].second;
	}
	for(int i=0;i<n;i++)cout<<ans[out[i]].first<<" "<<ans[out[i]].second<<"\n";
	return 0;
}