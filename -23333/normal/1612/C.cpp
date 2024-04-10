#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e5;
ll n,m;
__int128 js(__int128 x)
{
	return x*(x+1)/2;
}
bool check(ll x)
{
	if (x>n)
	{
		return -js(2*n-1-x)+2*((__int128)(1+n)*n/2)-n>=m; 
	} else
	{
		return js(x)>=m;
	}
}
int main()
{
	ios::sync_with_stdio(false);
    int T;
	cin>>T;
	while (T--)
	{   
	    cin>>n>>m;
	    ll h=1,t=2*n-1;
	    while (h<t)
	    {
	    	int mid=(h+t)/2;
	    	if (check(mid)) t=mid;
	    	else h=mid+1;
	    }
	    cout<<h<<endl;
    }
	return 0; 
}