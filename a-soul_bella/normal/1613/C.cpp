#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[10005],n,h;
inline bool check(int x)
{
	int nowr=0,qwq=0;
	for(int i=1;i<=n;i++)
	{
		int l=a[i],r=a[i]+x;
		if(l>=nowr) qwq+=r-l;
		else
			qwq+=r-nowr;
		nowr=r;
	}
	return qwq>=h;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> h;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		int l=0,r=h,ans;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid)) ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout << ans << "\n";
	}
	return 0;
}