#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int dist(int x1, int y1, int x2, int y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int32_t main()
{
    IOS;
    char a, b;
    int x, y;
    cin>>a>>x>>b>>y;
    int x1=a-'a'+1;
    int y1=x;
    int x2=b-'a'+1;
    int y2=y;
    int ans=0;
    for(int i=1;i<=8;i++)
    {
    	for(int j=1;j<=8;j++)
    	{
    		if(i==x1 || j==y1)
    			continue;
    		if(i==x2&&j==y2)
    			continue;
    		if(dist(i, j, x1, y1)==5 || dist(i, j, x2, y2)==5)
    			continue;
    		ans++;
    	}
    }
    cout<<ans;
    return 0;
}