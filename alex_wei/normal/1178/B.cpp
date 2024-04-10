#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,a[1000002],b[1000002];
string s;
int main()
{
	cin>>s;
	for(int i=2;i<=s.size();i++)
		a[i]=a[i-1]+(s[i-2]=='v'&&s[i-1]=='v');
	for(int i=s.size();i>1;i--)
		b[i]=b[i+1]+(s[i-2]=='v'&&s[i-1]=='v');
	for(int i=1;i<=s.size();i++)
		if(s[i-1]=='o')
			ans+=a[i]*b[i];
	cout<<ans;
	return 0;
}