#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],b[200005],n;
inline bool check(int x)
{
	for(int i=1;i<=n;i++) a[i]=b[i];
	for(int i=n;i>=3;i--)
	{
		int k=min((a[i]-x)/3,b[i]/3);
		if(a[i]<x) return 0;
		a[i]-=k*3;
		a[i-1]+=k,a[i-2]+=k+k;
	}
	return a[1]>=x&&a[2]>=x;
}
signed main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> b[i];
		int l=0,r=2e9,ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid)) l=mid+1,ans=mid;
			else r=mid-1;
		}
		cout << ans << "\n";
	}
	return 0;
}