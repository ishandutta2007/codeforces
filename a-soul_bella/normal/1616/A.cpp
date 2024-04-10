#include <bits/stdc++.h>
#define int long long
using namespace std;
int cnt[1005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		memset(cnt,0,sizeof cnt);
		cin >> n;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin >> x;
			x=max(x,-x);
			if(x) ans+=++cnt[x]<=2;
			else ans+=++cnt[x]<=1;
		}
		cout << ans << "\n";
	}
	return 0;
}