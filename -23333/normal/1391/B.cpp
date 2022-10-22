#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
int f[200][200];
int a[200][200];
char s[200];
int main()
{
	int t;
	cin>>t;
	rep(i,1,t)
	{
		int n,m;
		cin>>n>>m;
		rep(i,1,n)
		{ 
		  cin>>s;
		  rep(j,1,m) if (s[j-1]=='R') a[i][j]=1;
		  else a[i][j]=0;
	    }
	    int cnt=0;
	    rep(i,1,n-1) if (a[i][m]==1) cnt++;
	    rep(i,1,m-1) if (a[n][i]==0) cnt++;
	    cout<<cnt<<endl;
	}
	return 0;
}