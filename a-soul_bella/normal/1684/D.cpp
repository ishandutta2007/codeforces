#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=2e8;
int a[200005];
pair <int,int> b[200005];
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
		int now=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			now+=a[i];
			b[i]={a[i]-(n-i),i};
		}
		sort(b+1,b+n+1);
		reverse(b+1,b+n+1);
		int ans=now;
		for(int i=1;i<=k;i++)
		{
			now-=b[i].first;
			now-=i-1;
			ans=min(ans,now);
		}
		cout << ans << "\n";
	}
	return 0;
}