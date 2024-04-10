#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, sz;
int x[N], y[N];
int cache[N][2];
map<int, vector<pair<int, int> > > m;
vector<pair<int, vector<pair<int, int> > > > v;
vector<int> cost;

int manhattan(pair<int, int> &p1, pair<int, int> &p2)
{
	return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

int dp(int idx, int cur)
{
	if(idx==sz-1)
		return cost[idx];
	int &ans=cache[idx][cur];
	if(ans!=-1)
		return ans;
	ans=cost[idx];
	int temp;
	if(!cur)
		temp=min(dp(idx+1, 0) + manhattan(v[idx].second.back(), v[idx+1].second[0]), dp(idx+1, 1) + manhattan(v[idx].second.back(), v[idx+1].second.back()));
	else
		temp=min(dp(idx+1, 0) + manhattan(v[idx].second[0], v[idx+1].second[0]), dp(idx+1, 1) + manhattan(v[idx].second[0], v[idx+1].second.back()));
	ans+=temp;
	return ans;
}

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
	if(p1.second!=p2.second)
		return p1.second<p2.second;
	return p1.first>p2.first;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		m[max(x[i], y[i])].push_back({x[i], y[i]});
	}
	for(auto &it:m)
	{
		sort(it.second.begin(), it.second.end(), comp);
		v.push_back(it);
		pair<int, int> p2=it.second.back();
		pair<int, int> p1=it.second[0];
		cost.push_back(abs(p1.first-p2.first) + abs(p1.second-p2.second));
	}
	sz=v.size();
	pair<int, int> origin={0, 0};
	int ans=min(dp(0, 0) + manhattan(v[0].second[0], origin), dp(0, 1) + manhattan(v[0].second.back(), origin));
	cout<<ans;
	return 0;
}