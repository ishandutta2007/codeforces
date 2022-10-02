#include <bits/stdc++.h>
#define mod 1000000007
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
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=n-1;i>=1;i-=2)
			if(i+1<=n&&a[i]>a[i+1]) swap(a[i],a[i+1]);
		int flag=1;
		for(int i=2;i<=n;i++)
			if(a[i]<a[i-1]) flag=0;
		if(!flag) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}