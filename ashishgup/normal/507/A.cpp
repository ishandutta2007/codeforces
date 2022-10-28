#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n, k;
pair<int, int> a[N];

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1, a+n+1);
	vector<int> ans;
	for(int i=1;i<=n;i++)
	{
		if(k-a[i].first>=0)
		{
			ans.push_back(a[i].second);
			k-=a[i].first;
		}
	}
	cout<<ans.size()<<endl;
	for(auto &it:ans)
		cout<<it<<" ";
	return 0;
}