#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=2e5+5;

int n;
int a[N], deg[N];

int32_t main()
{
    IOS;
   	cin>>n;
   	for(int i=1;i<=n;i++)
   	{
   		cin>>a[i];
   		deg[i]++;
   		deg[a[i]]++;
   	}
   	int ans=0;
   	for(int i=1;i<=n;i++)
   	{
   		if(deg[i]==1)
   			ans++;
   	}
   	cout<<ans;
    return 0;
}