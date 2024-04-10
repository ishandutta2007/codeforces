#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define x first
#define y second

const int N=105;

int n;
pair<pair<int, int>, int> a[N];
set<int> ans;
int output[N];

bool comp(pair<pair<int, int>, int> &p1, pair<pair<int, int>, int> &p2)
{
	if(p1.x.y==p2.x.y)
		return p1.x.x<p2.x.x;
	return p1.x.y<p2.x.y;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x.x>>a[i].x.y;
		a[i].y=i;
	}
	sort(a+1, a+n+1, comp);
	for(int i=1;i<=n;i++)
	{
		int cur=a[i].x.x;
		while(ans.find(cur)!=ans.end())
			cur++;
		ans.insert(cur);
		output[a[i].y]=cur;
	}
	for(int i=1;i<=n;i++)
		cout<<output[i]<<" ";
	return 0;
}