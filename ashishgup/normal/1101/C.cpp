#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, check;
int l[N], r[N], ans[N];
map<int, vector<int> > m;

int32_t main()
{
	IOS;
	int t;
	cin>>t;
	while(t--)
	{
		m.clear();
		cin>>n;
		check=0;
		for(int i=1;i<=n;i++)
		{
			ans[i]=0;
			cin>>l[i]>>r[i];
			m[l[i]].push_back(i);
			m[r[i]+1].push_back(-i);
		}
		int cur=0, st=0;
		set<int> active;
		for(auto &it:m)
		{
			for(auto &i:it.second)
			{
				if(i<0)
				{
					cur--;
				}
			}
			if(cur==0 && active.size()<n && active.size()>0)
			{
				check=1;
				for(auto &it:active)
					ans[it]=1;
				break;
			}
			for(auto &i:it.second)
			{
				if(i>0)
				{
					cur++;
					active.insert(i);
				}
			}
		}
		if(!check)
		{
			cout<<"-1"<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(!ans[i])
				cout<<2<<" ";
			else
				cout<<1<<" ";
		}
		cout<<endl;
	}
	return 0;
}