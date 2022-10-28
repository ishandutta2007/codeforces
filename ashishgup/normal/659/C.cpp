#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m;
int a[N];
set<int> have;
vector<int> ans;

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		have.insert(a[i]);
	}
	for(int i=1;;i++)
	{
		if(have.find(i)!=have.end())
			continue;
		if(m<i)
			break;
		m-=i;
		ans.push_back(i);
	}
	cout<<ans.size()<<endl;
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}