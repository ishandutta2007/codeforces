#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n;
int ans=0;

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	int k;
    	cin>>k;
    	ans+=abs(k);
    }
    cout<<ans;
    return 0;
}