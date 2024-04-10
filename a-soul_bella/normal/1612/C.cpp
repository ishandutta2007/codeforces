#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int n,x;
		cin >> n >> x;
		int l=0,r=n*2-1,ans=n*2-1;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int qwq=0;
			if(mid<=n) qwq=mid*(mid+1)/2;
			else
			{
				int t=n*2-1-mid;
				qwq=n*n-t*(t+1)/2;
			}
			if(qwq>=x) ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout << ans << "\n";
	}
	return 0;
}