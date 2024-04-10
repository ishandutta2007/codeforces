#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;
const double PI=acosl(-1);

int n;
pair<double, int> angle[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		double x, y;
		cin>>x>>y;
		angle[i-1].first=atan2l(y, x) * (180/PI);
		angle[i-1].second=i;
	}
	sort(angle, angle+n);
	double maxdiff=360;
	pair<int, int> ans;
	for(int i=0;i<n;i++)
	{
		double diff=abs(angle[i].first-angle[(i+1)%n].first);
		diff=min(diff, 360-diff);
		if(diff<maxdiff)
		{
			maxdiff=diff;
			ans={angle[i].second, angle[(i+1)%n].second};
		}
	}
	cout<<ans.first<<" "<<ans.second;
	return 0;
}