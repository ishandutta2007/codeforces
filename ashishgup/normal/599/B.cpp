#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int f[N], b[N], idx[N], cnt[N];
vector<int> ans;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		cnt[f[i]]++;
		idx[f[i]]=i;
	}	
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		ans.push_back(idx[b[i]]);
	}
	for(int i=1;i<=m;i++)
	{
		if(!cnt[b[i]])
		{
			cout<<"Impossible";
			return 0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(cnt[b[i]]>1)
		{
			cout<<"Ambiguity";
			return 0;
		}
	}
	cout<<"Possible"<<endl;
	for(auto &it:ans)
		cout<<it<<" ";
	return 0;
}