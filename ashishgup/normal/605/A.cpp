#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N], ans[N];

int32_t main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int len=1;
	for(int i=1;i<=n;i++)
	{
		ans[a[i]]=max(ans[a[i]], ans[a[i]-1] + 1);
		len=max(len, ans[a[i]]);
	}   
	cout<<n-len;
}