//Started Late

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, q, sum = 0;
int a[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum += a[i];
	}
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	cin>>q;
	while(q--)
	{
		int x;
		cin>>x;
		int ans = sum - a[x];
		cout<<ans<<endl;
	}
	return 0;
}