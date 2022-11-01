#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (111)
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
const ld PI=(ld)2*asin(1);
string s,k;
ll ans=(ll)1e9;

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>k;
	if(s.size()>=k.size())
	{
		for(ll i=0;i<=(ll)s.size()-(ll)k.size();i++)
		{
			ll ex=0;
			for(ll j=i;j<i+(ll)k.size();j++)
				if(k[j-i]!=s[j])
					ex++;
			ans=min(ans,ex);		
		}
		for(ll i=s.size()-1;(ll)s.size()-i<(ll)k.size();i--)
		{
			ll ex=0;
			for(ll j=i;j<s.size();j++)
				if(k[j-i]!=s[j])
					ex++;
			ans=min(ans,ex+(ll)k.size()-((ll)s.size()-i));		
		}
		for(ll i=0;i<(ll)k.size()-1;i++)
		{
			ll ex=0;
			for(ll j=i,p=k.size()-1;j>=0;j--,p--)
				if(k[p]!=s[j])
					ex++;
			ans=min(ans,ex+(ll)k.size()-i-1);		
		}
		return cout<<ans,0;
	}
	else
	{
		swap(s,k);
	if(s.size()>=k.size())
	{
		for(ll i=0;i<=(ll)s.size()-(ll)k.size();i++)
		{
			ll ex=0;
			for(ll j=i;j<i+(ll)k.size();j++)
				if(k[j-i]!=s[j])
					ex++;
			ans=min(ans,ex);		
		}
		for(ll i=s.size()-1;(ll)s.size()-i<(ll)k.size();i--)
		{
			ll ex=0;
			for(ll j=i;j<s.size();j++)
				if(k[j-i]!=s[j])
					ex++;
			ans=min(ans,ex+(ll)k.size()-((ll)s.size()-i));		
		}
		for(ll i=0;i<(ll)k.size()-1;i++)
		{
			ll ex=0;
			for(ll j=i,p=k.size()-1;j>=0;j--,p--)
				if(k[p]!=s[j])
					ex++;
			ans=min(ans,ex+(ll)k.size()-i-1);		
		}
		return cout<<ans+abs((ll)k.size()-(ll)s.size()),0;
	}
	}
	return 0;
}