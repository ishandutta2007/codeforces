#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 100005;
const ll mod = 998244353 ;
ll n,b[N],c[N],ans,num[50],po[50];
string s[N];
int main()
{
	cin>>n;
	po[0]=1;
	for(ll i=1;i<50;i++)
		po[i]=(po[i-1]*10)%mod;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		num[s[i].size()]++;
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=s[i].size();j++){
			ll c=0;
			for(ll k=s[i].size()-1;k>=0;k--)
				c=(c+(s[i][s[i].size()-k-1]-'0')*po[k>=j?k+j:k*2+1])%mod;
			if(j<s[i].size())
				ans=(ans+c*(num[j]))%mod;
			else{
				ll cnt=0;
				for(ll k=18;k>=s[i].size();k--)
					cnt+=num[k];
				ans=(ans+c*cnt)%mod;
			}
			c=0;
			for(ll k=s[i].size()-1;k>=0;k--)
				c=(c+(s[i][s[i].size()-k-1]-'0')*po[k>=j?k+j-1:k*2])%mod;
			if(j==s[i].size())
			{
				ll cnt=0;
				for(ll k=18;k>=((ll)s[i].size()-1);k--)
					cnt+=num[k];
				ans=(ans+c*cnt)%mod;
			}
			else if(j>1)
				ans=(ans+c*(num[j-1]))%mod;
		}
	}
	cout<<ans%mod;
    return 0;
}
/*
2
1000000000 1000000000
*/