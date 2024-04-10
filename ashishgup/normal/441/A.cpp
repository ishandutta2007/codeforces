#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, v;
vector<int> ans;

int32_t main()
{
	IOS;
	cin>>n>>v;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		bool check=0;
		for(int j=1;j<=k;j++)
		{
			int cur;
			cin>>cur;
			check|=(v>cur);
		}
		if(check)
			ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(auto &it:ans)
		cout<<it<<" ";
	return 0;
}