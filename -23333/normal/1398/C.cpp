#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e5+10;
const int N2=2e6;
int t;
char c[N];
int a[N],sum[N];
int b[N2];
int main()
{
	cin>>t;
	rep(i,1,t)
	{
	   int n;
	   cin>>n;
	   b[n]=1;
	   cin>>c;
	   rep(i,1,n) a[i]=c[i-1]-'0',a[i]+=a[i-1];
	   ll ans=0;
	   rep(i,1,n)
	   {
	   	  int y=a[i]-i+n;
	   	  ans+=b[y];
	   	  b[y]++;
       }
	   rep(i,1,n)
	   {
	   	  int y=a[i]-i+n;
	   	  b[y]--;
       }
       b[n]=0;
       cout<<ans<<endl;
	}
	return 0;
}