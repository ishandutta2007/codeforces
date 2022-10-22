#include <bits/stdc++.h>
#define rep(i,h,t) for (int i=h;i<=t;i++)
using namespace std;
const int N=3e5;
char s[N];
int a[N];
int main()
{
	int n;
	cin>>n;
	rep(i,1,n)
	{
		cin>>s;
		int l=strlen(s);
		int cnt=0;
		rep(i,0,l-1)
		  if (s[i]=='B')
		  {
		    if (cnt>0) cnt--; else cnt++;
		  } else cnt++;
		cout<<cnt<<endl; 
	}
	return 0; 
}