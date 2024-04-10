#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n, ans=0;
int a[N], f[N];
set<int> totake, taken;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		f[a[i]]++;
	}
	for(int i=1;i<=n;i++)	
	{
		if(!f[i])
			totake.insert(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(taken.find(a[i])!=taken.end())
		{
			ans++;
			int cur=*(totake.begin());
			f[a[i]]--;
			a[i]=cur;
			f[a[i]]++;
			totake.erase(cur);
			taken.insert(cur);
		}	
		else
		{
			if(f[a[i]]>1)
			{
				int cur=*(totake.begin());
				if(cur>a[i])
				{
					f[a[i]]--;
					taken.insert(a[i]);
				}
				else
				{
					ans++;
					f[a[i]]--;
					a[i]=cur;
					f[a[i]]++;
					totake.erase(cur);
					taken.insert(cur);
				}
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}