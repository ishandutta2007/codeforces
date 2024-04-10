#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, ct=0;
int a[N];
map<int, int> m;
set<int> s;

void preprocess()
{
	for(int i=0;i<=1e5;i++)
	{
		s.insert(i*i);
	}
}

int32_t main()
{
	IOS;
	preprocess();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
		if(s.find(a[i])!=s.end())
		{
			ct++;
		}
	}
	sort(a+1, a+n+1);
	if(ct<=n/2)
	{
		int ans=0;
		int to_change=n/2-ct;
		multiset<int> ops;
		for(int i=1;i<=n;i++)
		{
			if(s.find(a[i])!=s.end())
				continue;
			auto it=s.upper_bound(a[i]);
			int cur=*it - a[i];
			if(it!=s.begin())
			{
				it--;
				cur=min(cur, a[i]-*it);
			}
			ops.insert(cur);
		}
		for(auto it:ops)
		{
			if(to_change==0)
				break;
			ans+=it;
			to_change--;
		}
		cout<<ans;
	}
	else
	{
		int extra=ct-n/2;
		int zeroes=m[0];
		int others=ct-zeroes;
		int ans=0;
		int store=min(others, extra);
		ans+=store*1;
		others-=store;
		extra-=store;
		if(extra>0)
		{
			ans+=2*extra;
		}
		cout<<ans;
	}
   	return 0;
}