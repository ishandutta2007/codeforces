#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
const ll mod=1e9+7;
ll po[102],ans=0;
int main()
{
	po[0]=1;
	for(int i=1;i<101;i++)
		po[i]=(po[i-1]*2)%mod;
	cin>>s;
	reverse(s.begin(),s.end());
	for(int i=0;i<s.size();i++)
		if(s[i]-'0')
			ans=(ans+po[i]*po[i]%mod*po[s.size()-i-1])%mod;
	cout<<ans;
	return 0;
}