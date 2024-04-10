#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
int T,n,m;
const int N=3e5;
int a[N];
char s[N];
int M[100];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		//cin>>n>>m;
		cin>>s;
		int n=strlen(s),pos=n;
		rep(i,1,n-1)
		  if (s[i]==s[0])
		  { 
		    pos=i; break;
		  }
		int gg=0; 
		rep(i,0,pos-1)
		{ 
		  M[s[i]-'a']++;
		  if (M[s[i]-'a']>1) gg=1;
	    }
	    if (gg) cout<<"NO"<<endl;
	    else
	    if (pos==n) cout<<"YES"<<endl;
	    else
	    {
	    	bool tt=1;
	    	rep(i,pos,n-1)
	    	  if (s[i]!=s[i-pos]) tt=0;
	    	if (tt) cout<<"YES"<<endl;
	    	else cout<<"NO"<<endl;
	    }
	    rep(i,0,26) M[i]=0;
	}
	return 0;
}