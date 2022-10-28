#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 5e5 + 5;

int n, ans = 0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i + n] = a[i];
	}
	for(int i=1, j=1;i<=2*n;i = j)
	{
		while(j<=2*n && a[j]==a[i])
			j++;
		if(a[i] == 1)
			ans = max(ans, j - i);
	}
	cout<<ans;
	return 0;
}