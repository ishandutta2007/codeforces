#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll calc(ll x){return (k-x+1+k)*x/2;}
ll ef(ll l,ll r)
{
	if(l==r)return l;
	ll m=l+r>>1;
	if(calc(m)>=n)return ef(l,m);
	else return ef(m+1,r);
}
int main()
{
	cin>>n>>k,k--;
	n--;
	if(calc(k)<n)cout<<-1,exit(0);
	cout<<ef(0,k);
	return 0;
}