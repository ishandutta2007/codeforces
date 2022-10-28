#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=10;

int n=8;
int x[N], y[N];
vector<int> xs, ys;
map<pair<int, int>, int> m;

int32_t main()
{
	IOS;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		xs.push_back(x[i]);
		ys.push_back(y[i]);
	}
	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());
	for(int i=1;i<=8;i++)
	{
		x[i]=lower_bound(xs.begin(), xs.end(), x[i]) - xs.begin();
		y[i]=lower_bound(ys.begin(), ys.end(), y[i]) - ys.begin();
		m[{x[i], y[i]}]=1;
	}
	int ans=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i==1 && j==1)
				continue;
			ans+=m[{i, j}];
		}
	}
	if(ans==8)
		cout<<"respectable";
	else
		cout<<"ugly";
	return 0;
}