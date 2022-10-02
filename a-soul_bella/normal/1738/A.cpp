#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],b[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,c0=0,c1=0;
		cin >> n;
		int S=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			if(a[i]) ++c1;
			else ++c0;
		}
		vector<int> v1,v0;
		for(int i=1;i<=n;i++)
		{
			cin >> b[i];
			S+=b[i];
			if(a[i]) v1.push_back(b[i]);
			else v0.push_back(b[i]);
		}
		sort(v1.begin(),v1.end());
		sort(v0.begin(),v0.end());
		if(c0!=c1)
		{
			c0=min(c0,c1+1);
			c1=min(c1,c0+1);
			if(c0>c1) --c0;
			else --c1;
			int ans=0;
			for(int i=(int)v1.size()-1;i>=0&&i>=v1.size()-c1;i--)
				ans+=v1[i];
			for(int i=(int)v0.size()-1;i>=0&&i>=v0.size()-c0;i--)
				ans+=v0[i];
			cout << ans+S << "\n";
		}
		else
		{
			int ans=0;
			for(int i=(int)v1.size()-1;i>=0&&i>=v1.size()-c1;i--)
				ans+=v1[i];
			for(int i=(int)v0.size()-1;i>=0&&i>=v0.size()-c0;i--)
				ans+=v0[i];
			cout << ans-min(v1[0],v0[0])+S << "\n";
		}
	}
	return 0;
}