#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define l first
#define r second

const int N = 5005;

int n, ans = 0;
int a[N];
map<int, vector<pair<int, int> > > m;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
	if(a.r != b.r)
		return a.r < b.r;
	return a.l < b.l;
}

int work(vector<pair<int, int> > &v)
{
	sort(v.begin(), v.end(), comp);
	int cur = 0, len = 0;
	for(auto &it:v)
	{
		if(it.first > cur)
		{
			cur = it.second;
			len++;
		}
	}	
	return len;
}

void work2(vector<pair<int, int> > &v)
{
	int cur = 0, len = 0;
	for(auto &it:v)
	{
		if(it.first > cur)
		{
			cur = it.second;
			cout<<it.first<<" "<<it.second<<endl;
		}
	}	
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int sum = 0;
		for(int j=i;j<=n;j++)
		{
			sum += a[j];
			m[sum].push_back({i, j});
		}
	}
	int best = 0;
	for(auto &it:m)
	{
		int cur = work(it.second);
		if(cur > ans)
		{
			ans = cur;
			best = it.first;
		}
	}
	cout<<ans<<endl;
	work2(m[best]);
	return 0;
}