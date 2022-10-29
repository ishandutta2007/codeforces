#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int nim[N], prefnim[N];
vector<pair<int, int> > sum[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)	
	{
		int cur=i;
		for(int j=i+1;j<=n;j++)
		{
			cur+=j;
			if(cur>n)
				break;
			sum[cur].push_back({i, j});
		}
	}	
	for(int i=1;i<=n;i++)
	{
		unordered_set<int> s;
		for(auto &it:sum[i])
			s.insert(prefnim[it.second]^prefnim[it.first-1]);
		int val=0;
		while(s.find(val)!=s.end())
			val++;
		nim[i]=val;
		prefnim[i]=prefnim[i-1]^nim[i];
	}
	if(nim[n]==0)
		cout<<"-1";
	else
	{
		int ans=1e9;
		for(auto &it:sum[n])
		{
			if((prefnim[it.second]^prefnim[it.first-1])==0)
				ans=min(ans, it.second-it.first+1);
		}
		cout<<ans;
	}
	return 0;
}