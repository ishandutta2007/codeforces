#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
    IOS;
    int x, y;
    cin>>x>>y;
    if(y==0)
    {
    	cout<<"No";
    	return 0;
    }
    if(y==1)
    {
    	if(x>0)
    	{
    		cout<<"No";
    		return 0;
    	}
    }
    int mincopies=y-1;
    if(x>=mincopies && (x-mincopies)%2==0)
    {
    	cout<<"Yes";
    }
    else
    {
    	cout<<"No";
    }
    return 0;
}