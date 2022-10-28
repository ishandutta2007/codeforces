#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int getsum(int x)
{
	return x*(x+1)/2;
}

int32_t main()
{
    IOS;
    int x;
    cin>>x;
    x=abs(x);
    int ans=0;
    while(getsum(ans)<x)
    	ans++;
    while((getsum(ans)-x)%2)
    	ans++;
    cout<<ans;
    return 0;
}