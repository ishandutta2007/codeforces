#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,l,r,k;
		cin >> n >> l >> r >> k;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int ans=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=r&&a[i]>=l)
			{
				if(a[i]<=k) k-=a[i],++ans;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}