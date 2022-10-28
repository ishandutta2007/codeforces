#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, a, b;
int v[N], ans[N];
map<int, vector<int> > m;

int32_t main()
{
    IOS;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
    	cin>>v[i];
    	m[v[i]].push_back(i);
    }
    if(a==b)
    {
    	for(int i=1;i<=a;i++)
    		cout<<"1 ";
    	for(int i=1;i<=b;i++)
    		cout<<"2 ";
    }
    else if(a<b)
    {
	    for(auto &it:m)
	    {
	    	reverse(it.second.begin(), it.second.end());
	    }
    	for(int i=1;i<=n;i++)
    		ans[i]=2;
    	auto it=--m.end();
    	while(a>0)
    	{
    		while((it->second).size()&&a>0)
    		{
    			a--;
    			int last=(it->second).back();
    			(it->second).pop_back();
    			ans[last]=1;
    		}
    		it--;
    	}
    	for(int i=1;i<=n;i++)
    	{
    		cout<<ans[i]<<" ";
    	}
    }
    else
    {
    	for(int i=1;i<=n;i++)
    		ans[i]=1;
    	auto it=--m.end();
    	while(b>0)
    	{
    		while((it->second).size()&&b>0)
    		{
    			b--;
    			int last=(it->second).back();
    			(it->second).pop_back();
    			ans[last]=2;
    		}
    		it--;
    	}
    	for(int i=1;i<=n;i++)
    	{
    		cout<<ans[i]<<" ";
    	}
    }
    return 0;
}