#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int a[N], ans[N];
map<int, vector<int> > v;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		v[a[i]].push_back(i);
	}
	for(int done=1;done<=m;done++)
	{
		int idx=0;
		bool check=1;
		for(int i=1;i<=n;i++)
		{	
			if(v[i].size()<done)
			{
				check=0;
				break;
			}
			idx=max(idx, v[i][done-1]);
		}
		if(!check)
			break;
		ans[idx]=1;
	}	
	for(int i=1;i<=m;i++)
		cout<<ans[i];
	return 0;
}