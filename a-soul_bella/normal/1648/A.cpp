#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> vx[100005],vy[100005];
inline int cal(vector <int> v)
{
	int now=1-(int)v.size();
	int ans=0;
	for(auto t:v)
		ans+=t*now,now+=2;
	return ans;
}
signed main()
{
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			cin >> x;
			vx[x].push_back(i);
			vy[x].push_back(j);
		}
	}
	int ans=0;
	for(int i=1;i<=100000;i++)
	{
		sort(vx[i].begin(),vx[i].end());
		sort(vy[i].begin(),vy[i].end());
		ans+=cal(vx[i]);
		ans+=cal(vy[i]);
	}
	cout << ans;
	return 0;
}