#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n, p;
int indeg[N], outdeg[N], nxt[N], diam[N];

int32_t main()
{
	IOS;
	cin>>n>>p;
	for(int i=1;i<=p;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		indeg[v]++;
		outdeg[u]++;
		nxt[u]=v;
		diam[u]=w;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans+=(outdeg[i]>0 && indeg[i]==0);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		if(outdeg[i]>0 && indeg[i]==0)
		{
			int idx=i, val=1e9;
			while(outdeg[idx])
			{
				val=min(val, diam[idx]);
				idx=nxt[idx];
			}
			cout<<i<<" "<<idx<<" "<<val<<endl;
		}
	}
	return 0;
}