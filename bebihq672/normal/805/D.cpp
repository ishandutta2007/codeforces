#include<iostream>
#include<cstring>
using namespace std;
const long long mod=1000000007;
char s[1010101];
int main()
{
	long long tmp=0;
	long long ans=0;
	cin>>s+1;
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	if(s[i]=='a')
	{
		tmp*=2;
		tmp+=s[i]-'a'+1;
		tmp%=mod;
	}
	else
	{
		ans+=tmp;
		if(ans>=mod)
			ans-=mod;
	}
	cout<<ans<<endl;
	return 0;
}