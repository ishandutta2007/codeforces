#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--) 
int n,m;
const int N=1000;
char s[N];
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		cin>>s;
		bool tt=0;
		rep(i,0,n-1)
		  if (s[i]!=s[n-1-i]) tt=1;
		if (!m) tt=0;
		if (tt) cout<<2<<endl; else cout<<1<<endl;
	}
	return 0;
}