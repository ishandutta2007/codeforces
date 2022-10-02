#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[50005],b[50005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		vector <pair<int,int> > va,vb;
		int n,k,m,s1=0,s2=0;
		cin >> n >> k;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			int x=a[i],y=1;
			while(x%k==0) x/=k,y*=k;
			if(va.empty()||va.back().first!=x) va.push_back({x,y});
			else va.back().second+=y;
		}
		cin >> m;
		for(int i=1;i<=m;i++)
		{
			cin >> b[i];
			int x=b[i],y=1;
			while(x%k==0) x/=k,y*=k;
			if(vb.empty()||vb.back().first!=x) vb.push_back({x,y});
			else vb.back().second+=y;
		}
		if(va==vb) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}