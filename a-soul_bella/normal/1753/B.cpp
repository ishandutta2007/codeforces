#include <bits/stdc++.h>
#define int long long 
using namespace std;
int a[500005],cnt[500005];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,x;
	cin >> n >> x;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]<x) ++cnt[a[i]];
	}
	for(int i=1;i<x;i++)
	{
		cnt[i+1]+=cnt[i]/(i+1);
		if(cnt[i]%(i+1))
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}