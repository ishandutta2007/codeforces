#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 100005;
const ll mod = 998244353 ;
ll n,b[N],c[N],ans;
string s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=0;j<s.size();j++)
			b[i]=(b[i]*10+s[j]-'0')*10%mod,c[i]=(c[i]*100+s[j]-'0')%mod;
	}
	for(int i=1;i<=n;i++)
		ans=(ans+b[i]*n)%mod,ans=(ans+c[i]*n)%mod;
	cout<<ans;
    return 0;
}