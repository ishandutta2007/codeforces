#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
	ll x=0,sign=1;char s=getchar();
	while(!isdigit(s)){if(s=='-')sign=-1;s=getchar();}
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x*sign;
}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
ll n,a[400002],num;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll d=a[1];
	for(int i=2;i<=n;i++)
		d=gcd(d,a[i]);
	for(ll i=1;i<=sqrt(d);i++)
		if(d%i==0){
			if(i*i==d)num++;
			else num+=2;
		}
	cout<<num;
	return 0;
}