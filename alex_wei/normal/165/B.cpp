#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll check(ll x)
{
	ll ans=0;
	while(x)ans+=x,x/=k;
	return ans;
}
int ef(int l,int r)
{
	if(l==r)return l;
	int m=l+r>>1;
	if(check(m)<n)return ef(m+1,r);
	else return ef(l,m);
}
int main()
{
	cin>>n>>k;
	cout<<ef(1,n);
	return 0;
}