#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e7+5;

int n, m, k;
int f[N], have[N], prv[N];
pair<int, int> s[N];
vector<int> ans;

int getp(int x)
{
	while(x>=0 && x!=prv[x])
	{
		if(prv[x]<0)
			return -1;
		prv[x]=prv[prv[x]];
		x=prv[x];
	}
	return x;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=0;i<=1e7;i++)
	{
		prv[i]=i;
		have[i]=k;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		int idx=getp(f[i]);
		if(idx<0)
		{
			cout<<"-1";
			return 0;
		}
		have[idx]--;
		if(have[idx]==0)
		{
			if(idx>0)
				prv[idx]=prv[idx-1];
			else
				prv[idx]=-1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s[i].first;
		s[i].second=i;
	}
	sort(s+1, s+m+1);
	reverse(s+1, s+m+1);
	for(int i=1;i<=m;i++)
	{
		int idx=getp(s[i].first);
		if(idx<0)
			continue;
		have[idx]--;
		if(have[idx]==0)
		{
			if(idx>0)
				prv[idx]=prv[idx-1];
			else
				prv[idx]=-1;
		}
		ans.push_back(s[i].second);
	}
	cout<<ans.size()<<endl;
	for(auto &it:ans)
		cout<<it<<" ";
	return 0;
}