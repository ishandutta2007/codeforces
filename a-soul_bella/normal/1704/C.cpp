#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=m;i++)
			cin >> a[i];
		sort(a+1,a+m+1);
		vector<int> v;
		a[0]=a[m]-n;
		for(int i=1;i<=m;i++)
			v.push_back(a[i]-a[i-1]-1);
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		int ans=0;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==4*i+1) ans++;
			else ans+=max(0ll,v[i]-1-4*i);
		}
		cout << n-ans << "\n"; 
	}
	return 0;
}