#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;

int n;
set<int> s[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		for(int j=1;j<=m;j++)
		{
			int cur;
			cin>>cur;
			s[i].insert(cur);
		}
	}
	for(int i=1;i<=n;i++)
	{
		bool check=1;
		for(int j=1;j<=n&&check;j++)
		{
			if(i==j)
				continue;
			bool cur=0;
			for(auto &it:s[j])
			{
				cur|=(s[i].find(it)==s[i].end());
				if(cur)
					break;
			}
			check&=cur;
		}
		if(check)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}