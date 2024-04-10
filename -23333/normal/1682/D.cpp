#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=5e5;
int n;
char s[N];
int C(int x)
{
	return x>n?x-n:x; 
}
int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n;
		cin>>s;
		int ans=0,pos=-1;
		for(int i=0;i<n;i++)
		{ 
		  ans^=(s[i]-'0');
		  if (s[i]=='1') pos=i;
	    }
	    for (int i=n;i<2*n;i++) s[i]=s[i-n];
		if (ans==1||pos==-1)
		{
			cout<<"NO"<<endl;
		} else
		{
			cout<<"YES"<<endl;
			pos++;
			int x=0,y=0;
			if (s[pos]=='1') x=pos+1;
			rep(i,pos+2,pos+n)
			  if (x>0&&y>0)
			  {
			  	cout<<C(y)<<" "<<C(i)<<endl;
			  	if (s[i-1]=='0') y=i; else y=0;
			  } else
			  if (x>0)
			  {
			  	cout<<C(x)<<" "<<C(i)<<endl;
			  	if (s[i-1]=='0') x=i; else x=0;
			  } else
			  {
			  	cout<<C(i-1)<<" "<<C(i)<<endl;
			  	x=i-1;
			  	if (s[i-1]=='0') y=i; else y=0;
		      }
		     assert(x==0&&y==0);
		}
	}
	return 0;
}
/*
3
4
1010
4
0101
4
0110
*/