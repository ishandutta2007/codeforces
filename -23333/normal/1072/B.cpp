#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
const int N=2e5;
int a[N],b[N],f[N];
int main()
{
  ios::sync_with_stdio(false);
	int n;
	cin>>n;
	rep(i,1,n-1) cin>>a[i];
	rep(i,1,n-1) cin>>b[i];
	rep(i,0,3)
	{
		int now=i;
		f[1]=now;
	  bool tt=0;
		rep(j,2,n)
	  {
	  	f[j]=-1;
	    rep(k,0,3)
	      if ((now|k)==a[j-1]&&(now&k)==b[j-1])
	        f[j]=k;
	    now=f[j];
	    if (f[j]==-1)
			{
			  tt=1; 
			  break;
			}
	  }
	  if (!tt)
	  {
	  	cout<<"YES"<<endl;
	  	rep(i,1,n) cout<<f[i]<<" ";
	  	exit(0);
	  }
	}
	cout<<"NO"<<endl;
	return 0;	
}