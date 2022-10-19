#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int n,m,c;
vector<int> x[N],y[N];
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			scanf("%d",&c);
			x[c].push_back(i);
			y[c].push_back(j);
		}
	ll ans=0;
	for (int i=1;i<=100000;++i)
		if (x[i].size())
		{
			sort(x[i].begin(),x[i].end());
			sort(y[i].begin(),y[i].end());
			ll sx=x[i][0],sy=y[i][0];
			for (int j=1;j<(int)x[i].size();++j)
			{
				ans+=(ll)j*(x[i][j]+y[i][j])-sx-sy;
				sx+=x[i][j];
				sy+=y[i][j];
			}
		}
	cout<<ans<<endl;
	return 0;
}