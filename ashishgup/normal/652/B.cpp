#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1005;

int n;
int a[N], ans[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	int idx=1;
	for(int i=1;i<=n;i+=2)
		ans[i]=a[idx++];
	for(int i=2;i<=n;i+=2)
		ans[i]=a[idx++];
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";	
	return 0;
}