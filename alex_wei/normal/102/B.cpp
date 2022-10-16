#include<bits/stdc++.h>
using namespace std;
string s;
int sum,ans=1;
int work()
{
	
}
int main()
{
	cin>>s;
	if(s.size()<2)cout<<0,exit(0);
	for(int i=0;i<s.size();i++)
		sum+=(s[i]^48);
	while(log10(sum)>=1.0){
		ans++;
		int nw=0;
		while(sum)nw+=sum%10,sum/=10;
		sum=nw;
	}
	cout<<ans<<endl;
	return 0;
}