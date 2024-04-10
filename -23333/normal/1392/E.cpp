#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
#define ll long long
const int N=30;
int n,q;
ll a[N][N];
ll b[100];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	b[0]=1;
	rep(i,1,50) b[i]=b[i-1]*2;
	rep(i,1,n)
	{
	  rep(j,1,n)
	  {
	    if (i%2==1) a[i][j]=b[i+j-2];
	    cout<<a[i][j]<<" ";
	    cout.flush();
	  }
	  cout<<endl; 
	  cout.flush();
    }
    cout<<endl; 
	  cout.flush();
    cin>>q;
    rep(i,1,q)
    {
    	ll k;
    	cin>>k;
    	int nowa=1,nowb=1;
    	cout<<1<<" "<<1<<endl;
    	cout.flush();
    	rep(j,1,n+n-2)
    	{
    	  if ((k>>j)&1)
    	  {
    	  	 if (a[nowa+1][nowb]>0||nowb==n) nowa=nowa+1; else nowb=nowb+1;
    	  } else
    	  {
    	  	if (a[nowa+1][nowb]>0||nowa==n) nowb=nowb+1; else nowa=nowa+1;
    	  }
    	  cout<<nowa<<" "<<nowb<<endl;
    	  cout.flush();
        }
        cout<<endl;
        cout.flush();
    }
	return 0;
}