#include <bits/stdc++.h>
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
using namespace std;
const int N=2e6;
int f[N],g[N];
int n,a[N],ve1[N],ve2[N];
int pd()
{
	int now=n-1,he=a[n];
	rep(i,1,n/2-1)
	{
		   while (!f[a[now]])
		   {
		   	 now--; 
		   }
		   ve1[i]=a[now]; 
		   f[a[now]]--;
		   int t=he-a[now];
		   if (f[t]) 
		   {
		   	 ve2[i]=t;
		   	 f[t]--; 
		   } else return 0;
		   he=a[now];
	}
	return 1; 
}
int main()
{
    int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		rep(i,1,2*n) cin>>a[i];
		sort(a+1,a+2*n+1);
		n*=2;
		bool tt=0;
		rep(i,1,n-1)
		{
		  rep(i,1,n) f[a[i]]=0;
		  rep(j,1,n-1) if (j!=i) f[a[j]]++; 
		  if (pd())
		  {
		  	tt=1;
		  	cout<<"YES"<<endl;
			cout<<a[n]+a[i]<<endl;
			cout<<a[n]<<" "<<a[i]<<endl;
			rep(i,1,n/2-1) cout<<ve1[i]<<" "<<ve2[i]<<endl;
		  	break;
	      }
		}
		rep(i,1,n) f[a[i]]=0;
		if (!tt) cout<<"NO"<<endl;
	}
	return 0;
}