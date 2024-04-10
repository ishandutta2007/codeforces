#include <bits/stdc++.h>
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
using namespace std;
const int N=2e6;
int a[N],b[N],f[N];
int main()
{
    int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		rep(i,1,n) cin>>a[i];
		b[1]=a[1];
		rep(i,2,n) b[i]=a[i]-b[i-1];
	    f[n+1]=1e9; f[n+2]=1e9;
		dep(i,n,1) f[i]=min(b[i],f[i+2]);
		bool tt=0;
		int tt1=0;
		rep(i,1,n) if (b[i]<0) tt1=-1;
		if (tt1==0&&b[n]==0)
		{
			cout<<"YES"<<endl;
			continue;
		}
		rep(i,1,n-1)
		{
		if (b[i-1]<0) break;
		{
			int g1;
			if (n%2==i%2) g1=-2*(a[i]-a[i+1]); else g1=2*(a[i]-a[i+1]);
			if (a[i+1]-b[i-1]>=0&&a[i]-(a[i+1]-b[i-1])>=0&&(i+2>n||f[i+2] -2*(a[i]-a[i+1])>=0)
			    &&(i+3>n||f[i+3]+2*(a[i]-a[i+1])>=0)&&b[n]+g1==0)
			    {
			    	tt=1;
			    	cout<<"YES"<<endl;
					break; 
			    }
	    }
	    }
	    if (!tt) cout<<"NO"<<endl;
	}
	return 0;
}