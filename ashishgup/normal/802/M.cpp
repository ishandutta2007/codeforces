#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int a[N];

int32_t main()
{
	int n, k, ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	for(int i=1;i<=k;i++)
		ans+=a[i];
	cout<<ans;
	return 0;
}