#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
int n,m;
const int N=210;
int a[N],b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,1,n) cin>>a[i];
	rep(i,1,m) cin>>b[i];
	rep(i,0,1023)
	{
		bool t1=0;
		rep(j,1,n)
		{
		  bool tt=1;
		  rep(k,1,m)
		  {
		  	int x=a[j]&b[k];
		  	if ((i|x)==i) tt=0;
		  }
		  if (tt) t1=1;
	    }
	    if (!t1)
	    {
	    	cout<<i<<endl;
	    	return 0;
	    }
	}
	return 0;
}