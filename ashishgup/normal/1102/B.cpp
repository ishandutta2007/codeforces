#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n, k, col=0, check=0;
int a[N], ans[N];
map<int, vector<int> > m;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]].push_back(i);
	}
	for(auto &it:m)
	{
		if(it.second.size()>k)
		{
			cout<<"NO";
			return 0;
		}
		for(auto &i:it.second)
		{
			ans[i]=col;
			col++;
			check|=(col==k);
			col%=k;
		}
	}
	if(!check)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<ans[i]+1<<" ";
	return 0;
}