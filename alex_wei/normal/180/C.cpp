#include<bits/stdc++.h>
using namespace std;
string s;
int d[100002],x[100002],ans=1e5;
int main()
{
	cin>>s;
	for(int i=1;i<=s.size();i++)
		d[i]=d[i-1]+(s[i-1]>'Z');
	for(int i=s.size();i>0;i--)
		x[i]=x[i+1]+(s[i-1]<'a');
	for(int i=0;i<=s.size();i++)
		ans=min(ans,d[i]+x[i+1]);
	cout<<ans;
	return 0;
}