#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int k, a, b;

int f(int x)
{
	return x/k;
}

int32_t main()
{
    IOS;
    cin>>k>>a>>b;
    int ans=0;
    if(0>=a && 0<=b)
    	ans++;
    if(b>0)
    	ans+=f(b);
    else if(b<0)
    	ans-=f(abs(b)-1);
    if(a>0)
    	ans-=f(a-1);
    else if(a<0)
    	ans+=f(abs(a));
    cout<<ans;
    return 0;
}