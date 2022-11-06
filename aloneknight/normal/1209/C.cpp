#include<bits/stdc++.h>
using namespace std;
int n;string s,ss,ans;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		cin>>n>>s;ss=s;ans=s;
		sort(ss.begin(),ss.end());int id=0;
		for(int i=0;i<n;i++)if(s[i]==ss[id]){s[i]=1;ans[i]='1';id++;}
		for(int i=0;i<n;i++)if(s[i]==ss[id]){s[i]=1;ans[i]='2';id++;}
		if(id!=n)ans="-";cout<<ans<<endl;
	}
	return 0;
}