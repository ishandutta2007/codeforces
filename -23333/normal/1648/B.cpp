#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=2e6;
int a[N],b[N],sum[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{ 
	   int n,m;
	   cin>>n>>m;
	   int gg=0;
	   rep(i,1,n)
	   { 
	     cin>>a[i],b[a[i]]++;
	     gg=max(gg,a[i]);
	   }
	   rep(i,1,gg) sum[i]=sum[i-1]+b[i];
	   bool tt=1;
	   rep(i,1,gg)
	   {
	   	  if (b[i])
		  {
		  //	 if (sum[i+i-1]-sum[i-1]>1&&b[1]==0) tt=0;
		  	 for(int j=i;j<=gg;j+=i)
		  	   if (sum[min(gg,j+i-1)]-sum[j-1]>0&&b[j/i]==0) tt=0;
		  }
	   }
	   if (tt) cout<<"Yes"<<endl;
	   else cout<<"No"<<endl;
	   rep(i,1,gg) b[i]=0;
    }
	return 0;
}