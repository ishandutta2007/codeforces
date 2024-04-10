#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
int f[10];

int32_t main()
{
	IOS;
	cin>>f[2]>>f[3]>>f[5]>>f[6];
	int no1=min({f[2], f[5], f[6]});
	int no2=min(f[2]-no1, f[3]);
	int ans=256*no1 + 32*no2;
	cout<<ans;
	return 0;
}