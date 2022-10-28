#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, asz=0, bsz=0;
int a[N], ans[N];
stack<int> g[N];
set<int> s1, s2;

int32_t main()
{
	IOS;
	cin>>n;
	n=2*n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		g[a[i]].push(i);
	}
	for(int i=10;i<=99;i++)
	{
		if(g[i].size()==1)
		{
			if(asz > bsz)
			{
				bsz++;
				ans[g[i].top()]=2;
				g[i].pop();
				s2.insert(i);
			}
			else
			{
				asz++;
				ans[g[i].top()]=1;
				g[i].pop();
				s1.insert(i);
			}
		}
		else if(g[i].size()>=2)
		{
			asz++;
			bsz++;
			s1.insert(i);
			s2.insert(i);
			ans[g[i].top()]=1;
			g[i].pop();
			ans[g[i].top()]=2;
			g[i].pop();
		}
	}
	for(int i=10;i<=99;i++)
	{
		while(g[i].size())
		{
			if(asz > bsz)
			{
				bsz++;
				ans[g[i].top()]=2;
				g[i].pop();
				s2.insert(i);
			}
			else
			{
				asz++;
				ans[g[i].top()]=1;
				g[i].pop();
				s1.insert(i);
			}
		}
	}
	cout<<(s1.size() * s2.size())<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}