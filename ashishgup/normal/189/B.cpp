#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int32_t main()
{
    IOS;
    int h, w;
    cin>>h>>w;
    int ans=0;
    for(int i=2;i<=h;i+=2)
    {
    	for(int j=2;j<=w;j+=2)
    	{
    		ans+=(h-i+1)*(w-j+1);
    	}
    }
    cout<<ans;
    return 0;
}