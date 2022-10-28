#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, k;
int l[N], r[N];

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i];
	cin>>k;
	for(int i=1;i<=n;i++)
	{
		if(k>=l[i] && k<=r[i])
		{
			cout<<n - i + 1;
			return 0;
		}
	}
	return 0;
}