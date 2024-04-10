#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
map<pair<int, int>, int> m;
vector<pair<int, int> > ans;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=i+k;j++)
		{
			ans.push_back({i, j%n});
			m[{i, j%n}]++;
			m[{j%n, i}]++;
		}
	}
	for(auto it:m)
	{
		if(it.second>1)
		{
			cout<<"-1";
			return 0;
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
	{
		cout<<it.first+1<<" "<<it.second+1<<endl;
	}
	return 0;
}