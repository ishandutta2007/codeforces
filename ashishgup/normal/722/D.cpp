#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=50005;

int n;
int a[N];
vector<int> ans;
map<int, int> cur;

bool check(int k)
{
	ans.clear();
	cur.clear();
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=k)
			cur[a[i]]++;
		else
		{
			int elem=a[i];
			while(elem>k)
			{
				elem/=2;
			}
			cur[elem]++;
		}
	}
	while(cur.size())
	{
		pair<int, int> p=*(--cur.end());
		ans.push_back(p.first);
		if(p.first==1 && p.second>1)
			return 0;
		p.second-=1;
		cur.erase(--cur.end());
		if(p.second)
			cur[p.first/2]+=p.second;
	}
	return 1;
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
	check(lo);
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	binsearch(1, 1e9);
	for(auto it:ans)
		cout<<it<<" ";
	return 0;
}