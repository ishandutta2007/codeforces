#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, d, a, b;
pair<int, int> v[N];
vector<int> ans;

int32_t main()
{
	IOS;
	cin>>n>>d>>a>>b;
	for(int i=1;i<=n;i++)
	{
		int x, y;
		cin>>x>>y;
		v[i].first=x*a + y*b;
		v[i].second=i;
	}
	sort(v+1, v+n+1);
	for(int i=1;i<=n;i++)
	{
		if(d<v[i].first)
			break;
		d-=v[i].first;
		ans.push_back(v[i].second);
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
		cout<<it<<" ";
 	return 0;
}