#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, m, ans1=0, ans2=0;
int fm[N], fc[N];
map<int, int> marker[N], cap[N];

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x, y;
		cin>>x>>y;
		marker[y][x]++;
		fm[y]++;
	}
	for(int i=1;i<=m;i++)
	{
		int x, y;
		cin>>x>>y;
		cap[y][x]++;
		fc[y]++;
	}
	for(int i=1;i<=1000;i++)
	{
		ans1+=min(fm[i], fc[i]);
		for(auto &it:marker[i])
		{
			if(cap[i].find(it.first)!=cap[i].end())
				ans2+=min(it.second, cap[i][it.first]);
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}