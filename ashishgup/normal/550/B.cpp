#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=20;

int n, l, r, x, ans=0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>l>>r>>x;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int mask=0;mask<(1<<n);mask++)
	{
		if(__builtin_popcount(mask)<2)
			continue;
		vector<int> v;
		for(int j=0;j<n;j++)
		{
			if(mask>>j & 1)
				v.push_back(a[j]);
		}
		sort(v.begin(), v.end());
		int sum=0, diff=v.back()-v[0];
		for(auto &it:v)
			sum+=it;
		if(sum>=l && sum<=r && diff>=x)
			ans++;
	}
	cout<<ans;
	return 0;
}