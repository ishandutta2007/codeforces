#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2005;

int n, k;
int a[N], b[N];
set<int> ans;

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=k;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		multiset<int> m;
		for(int j=2;j<=k;j++)
			m.insert(b[j]);
		int cur=b[1];
		for(int j=i+1;j<=n;j++)
		{
			cur+=a[j];
			if(m.find(cur)!=m.end())
				m.erase(m.find(cur));
		}
		cur=b[1];
		for(int j=i;j>1;j--)
		{
			cur-=a[j];
			if(m.find(cur)!=m.end())
				m.erase(m.find(cur));
		}
		if(!m.size())
			ans.insert(cur-a[1]);
	}	
	cout<<ans.size();
	return 0;
}