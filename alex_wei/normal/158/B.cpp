#include<bits/stdc++.h>
using namespace std;
int n,s[5],p,ans;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>p,s[p]++;
	ans=s[4]+s[3];
	s[1]-=min(s[1],s[3]);
	if(s[2]%2==0)cout<<ans+s[2]/2+(s[1]==0?0:(s[1]-1)/4+1);
	else cout<<ans+s[2]/2+(s[1]+1)/4+1;
	return 0;
}