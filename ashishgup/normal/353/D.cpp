#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int m=0, wait=0, ans=0;
string s;

int32_t main()
{
    IOS;
    cin>>s;
    for(auto it:s)
    {
    	if(it=='M')
    	{
    		m++;
    		if(wait)
    			wait--;
    	}
    	else
    	{
    		if(m)
    		{
				ans=max(ans, m+wait);
				wait++;
    		}
    	}
    }
    cout<<ans;
    return 0;
}