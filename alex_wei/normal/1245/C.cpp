#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
string s;
ll ans=1,f[100005],invf[100005];
ll ksm(ll a,ll b){ll m=a,s=1;while(b){if(b&1)s=(s*m)%mod;m=m*m%mod;b>>=1;}return s;}
ll C(ll m,ll n)
{
	return f[n]*invf[n-m]%mod*invf[m]%mod;
}
ll calc(ll l)
{
//	cout<<l<<endl;
	ll mut=1;
	for(int i=1;i<=l/2;i++)
		mut=(mut+C(i,l-i))%mod;
//	cout<<mut<<endl;
	return mut;
}
int main()
{
	cin>>s;
	f[0]=invf[0]=1;
	f[1]=invf[1]=1;
	for(int i=2;i<=100000;i++)
		f[i]=(f[i-1]*i)%mod,invf[i]=ksm(f[i],mod-2);
	for(int i=0;i<s.size();i++){
		if(s[i]=='m'||s[i]=='w')cout<<0,exit(0);
		if(s[i]!='n'&&s[i]!='u')continue;
		int len=0;
		while(i+len<s.size()&&s[i+len]==s[i])len++;
		ans=ans*calc(len)%mod;
		i+=len-1;
	}
	cout<<ans;
    return 0;
}