#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;

int n, m, k;
int a[N];

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	fill(a+1, a+N, k);
	for(int i=1;i<=n;i++)
	{
		int r, c;
		cin>>r>>c;
		a[r]=min(a[r], c);
	}
	int ans=0;
	for(int i=1;i<=m;i++)
		ans+=a[i];
	ans=min(ans, k);
	cout<<ans;
 	return 0;
}