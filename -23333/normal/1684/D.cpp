#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
const int N=3e5;
int b[N],a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		ll sum=0;
		rep(i,1,n)
		{ 
		  cin>>a[i];
		  b[i]=a[i]-(n-i);
		  sum+=a[i];
	    }
	    sort(b+1,b+n+1); reverse(b+1,b+n+1);
	    rep(i,1,m) sum-=b[i];
	    sum-=1ll*m*(m-1)/2;
	    cout<<sum<<endl;
	}
	return 0;
}