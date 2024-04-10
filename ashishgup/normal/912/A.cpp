#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
   	int a, b, x, y, z;
   	cin>>a>>b>>x>>y>>z;
   	int reqda=x*2 + y*1;
   	int reqdb=y*1 + z*3;
   	int ans=max(reqda-a, 0LL) + max(reqdb-b, 0LL);
   	cout<<ans;
    return 0;
}