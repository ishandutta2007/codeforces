#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, a, b, ans=0;
int x[N], y[N];

void calc(int x1, int y1, int x2, int y2)
{
	if((x1+x2)<=a && max(y1, y2)<=b)
		ans=max(ans, x1*y1 + x2*y2);
	if((x1+x2)<=b && max(y1, y2)<=a)
		ans=max(ans, x1*y1 + x2*y2);
}

int32_t main()
{
	IOS;
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			calc(x[i], y[i], x[j], y[j]);
			calc(x[i], y[i], y[j], x[j]);
			calc(y[i], x[i], x[j], y[j]);
			calc(y[i], x[i], y[j], x[j]);
		}
	}
	cout<<ans;
	return 0;
}