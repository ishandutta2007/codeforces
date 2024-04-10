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
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int l=0,r=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]==a[i+1])
			{
				if(!l) l=i;
				r=i;
			}
		}
		if(l==r) cout << "0\n";
		else cout << max(1ll,r-l-1) << "\n";
	}
	return 0;
}