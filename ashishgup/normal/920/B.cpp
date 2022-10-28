//Doesn't depend on the constraint Li<=Li+1

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int l[N], r[N];
priority_queue<int, vector<int>, greater<int> > tim[N];
int ans[N];

int32_t main()
{
    IOS;
    int t;
    cin>>t;
    while(t--)
    {
    	memset(ans, 0, sizeof(ans));
    	for(int i=1;i<=5000;i++)
 		{
 			while(!tim[i].empty())
 				tim[i].pop();
 		}
    	int n;
    	cin>>n;
    	for(int i=1;i<=n;i++)
    	{
    		cin>>l[i]>>r[i];
    		for(int j=l[i];j<=r[i];j++)
    		{
    			tim[j].push(i);
    		}
    	}
    	set<int> taken;
    	for(int i=1;i<=5000;i++)
    	{
    		while(!tim[i].empty() && taken.find(tim[i].top())!=taken.end())
    		{
    			tim[i].pop();
    		}
    		if(!tim[i].empty())
    		{
    			ans[tim[i].top()]=i;
    			taken.insert(tim[i].top());
    		}
    	}
    	for(int i=1;i<=n;i++)
    	{
    		cout<<ans[i]<<" ";
    	}
    	cout<<endl;
    }
    return 0;
}