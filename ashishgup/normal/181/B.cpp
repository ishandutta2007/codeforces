#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=3005;

int n, ans=0;
int x[N], y[N];
map<pair<int, int>, int> m;

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		m[{x[i], y[i]}]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((x[i]+x[j])%2)
				continue;
			if((y[i]+y[j])%2)
				continue;
			int midx=(x[i]+x[j])/2;
			int midy=(y[i]+y[j])/2;
			if(m.find({midx, midy})!=m.end())
				ans++;
		}
	}
	cout<<ans;
	return 0;
}