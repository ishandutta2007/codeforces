#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n;
int a[N];
set<int> s;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s.insert(a[i]);
	}
	sort(a+1, a+n+1);
	int ans=0;
	vector<int> store;
	int val=0;
	for(int gap=1;gap<=2e9;gap*=2)
	{
		for(int idx=1;idx<=n;idx++)
		{
			int curval=1;
			if(s.find(a[idx]-gap)!=s.end())
				curval++;
			if(s.find(a[idx]+gap)!=s.end())
				curval++;
			if(curval>val)
			{
				val=curval;
				store.clear();
				store.push_back(a[idx]);
				if(s.find(a[idx]-gap)!=s.end())
					store.push_back(a[idx]-gap);
				if(s.find(a[idx]+gap)!=s.end())
					store.push_back(a[idx]+gap);
			}
		}
	}
	cout<<store.size()<<endl;
	for(auto it:store)
		cout<<it<<" ";
	return 0;
}