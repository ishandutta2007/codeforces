#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,ans;
string s,t;
int main()
{
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)
		ans+=min(abs(s[i]-t[i]),min(abs(s[i]+10-t[i]),abs(t[i]+10-s[i])));
	cout<<ans;
	return 0;
}