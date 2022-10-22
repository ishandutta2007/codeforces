#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long 
int n,m;
const int N=1e6;
ll a[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{ 
	   cin>>n>>m;
	   if (n%2==0||m==1)
	   {
	   	  cout<<"YES"<<endl;
	   	  for (int i=1;i<=n;i+=2)
	   	  {
	   	  	 for (int j=m*(i-1)+1;j<=m*(i+1);j+=2) cout<<j<<" ";
	   	  	 cout<<endl;
	   	  	 if (i==n) break;
	   	  	 for (int j=m*(i-1)+2;j<=m*(i+1);j+=2) cout<<j<<" ";
	   	  	 cout<<endl;
	   	  }
	   } else cout<<"NO"<<endl;
	}
	return 0;
}