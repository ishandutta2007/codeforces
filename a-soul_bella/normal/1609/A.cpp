#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[10005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int mx=0;
		int n;
		cin >> n;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i];
			while(a[i]%2==0)
			{
				a[i]/=2;
				++cnt;
			}
			mx=max(mx,a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=a[i];
		ans-=mx;
		while(cnt--) mx*=2;
		cout << ans+mx << "\n";
	}
	return 0;
}