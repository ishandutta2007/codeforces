#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, ans=0;
string a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int mask=0;
		map<int, int> cur;
		for(auto &it:a[i])
			cur[it]++;
		for(auto &it:cur)
		{
			if(it.second%2)
				mask|=(1<<(it.first-'a'));
		}
		m[mask]++;
	}
	for(auto &it:m)
	{
		if(it.first==0)
		{
			ans+=(it.second*(it.second-1))/2;
			continue;
		}
		int mask=it.first;
		int covered=0;
		for(int j=0;j<26;j++)
		{	
			if((mask>>j) & 1)
			{
				int curmask=mask & (~(1<<j));
				if(curmask<mask)
				{
					if(m.find(curmask)!=m.end())
						ans+=it.second * m[curmask];
				}
			}
		}
		ans+=(it.second * (it.second-1))/2;
	}
	cout<<ans;
	return 0;
}