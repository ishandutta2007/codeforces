#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
const int N=1e6;
int n,m;
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>s;
		int n=strlen(s);
		int sum=0; bool tt=0,tt2=1;
		for (int i=0;i<n;i++)
		{
		  if (s[i]=='A') sum++; else sum--;
		  if (s[i]=='B') tt=1;
		  if (sum<0) tt2=0;
	    }
	    if (s[n-1]=='B'&&tt2) cout<<"YES"<<endl;
	    else cout<<"NO"<<endl;
	}
	return 0;
}