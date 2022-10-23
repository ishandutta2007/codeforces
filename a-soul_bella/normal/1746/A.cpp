#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
const int inf=1e18;
int a[1000005],n;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,k;
		cin >> n >> k;
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			flag|=a[i];
		}
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}