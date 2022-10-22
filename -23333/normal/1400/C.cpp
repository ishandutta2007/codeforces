#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++) 
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int t;
const int N=2e5;
char s[N];
int T,a[N],w;
int main()
{
	cin>>T;
	rep(i,1,T)
	{
		cin>>s; cin>>w;
		int n=strlen(s);
		rep(i,0,n-1)
		{
			if (s[i]=='0')
			{
			  if (i+1-w>0) a[i+1-w]=-1;
			  if (i+1+w<=n) a[i+1+w]=-1;
		    }
		}
		int tto=1;
		rep(i,0,n-1)
		{
		  bool tt=0;
		  if (s[i]=='1')
		  {
		  	if (i+1-w>0&&a[i+1-w]!=-1) tt=1;
		  	if (i+1+w<=n&&a[i+1+w]!=-1) tt=1; 
		  } else tt=1;
		  if (!tt) tto=-1;
	    }
	    if (tto==-1) cout<<-1<<endl;
	    else
	      rep(i,1,n) if (a[i]==-1) cout<<0; else cout<<1;
	    cout<<endl;
		rep(i,1,n) a[i]=0;
	}
	return 0; 
}