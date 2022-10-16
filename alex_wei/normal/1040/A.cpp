#include<bits/stdc++.h>
using namespace std;
int ans,n,a,b,s[50];
int main()
{
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n/2;i++)
		if(s[i]!=s[n-i+1]){
			if(s[i]!=2&&s[n-i+1]!=2)cout<<-1,exit(0);
			if(s[i]==0||s[n-i+1]==0)ans+=a;
			else ans+=b;
		}
		else if(s[i]==2)ans+=min(a,b)*2;
	cout<<ans+(n%2&&s[n/2+1]==2)*min(a,b);
	return 0;
}