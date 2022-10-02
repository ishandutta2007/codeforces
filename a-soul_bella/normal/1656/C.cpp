#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005];
map <int,int> mp;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n;
		int X=0,Y=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			X|=a[i]==1;
		}
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)
			if(a[i]==a[i-1]+1) Y=1;
		if(X&&Y) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}