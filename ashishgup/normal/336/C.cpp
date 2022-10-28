#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, beauty=-1;
int a[N];
set<int> ans;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans.insert(a[i]);
	}
	for(int cur=31;cur>=0;cur--)
	{
		int value=(1LL<<32)-1;
		set<int> v;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>>cur & 1)
			{
				value&=a[i];
				v.insert(a[i]);
			}
		}
		if(v.size() && (value)%(1LL<<cur)==0)
		{
			beauty=cur, ans=v;
			break;
		}
	}
	cout<<ans.size()<<endl;
	for(auto &it:ans)
		cout<<it<<" ";
	return 0;
}