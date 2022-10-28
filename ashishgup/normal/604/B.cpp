#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k;
int a[N];

int check(int sz)
{
	multiset<int> s;
	for(int i=1;i<=n;i++)
		s.insert(a[i]);
	int cnt=0;
	while(s.size())
	{
		cnt++;
		int elem=*(--s.end());
		if(elem>sz)
			return 0;
		s.erase(--s.end());
		auto it=s.upper_bound(sz-elem);
		if(it!=s.begin())
		{
			s.erase(--it);
		}
	}
	return cnt<=k;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=binsearch(1, 2e6);
	cout<<ans;
	return 0;
}