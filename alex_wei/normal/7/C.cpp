#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c,d,t,x,y;
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
void exgcd(ll a,ll b){if(!b){x=1,y=0;return;}exgcd(b,a%b);ll z=x;x=y,y=z-a/b*y;}
int main()
{
	cin>>a>>b>>c;
	c=-c;
	d=gcd(a,b);
	if(c%d!=0)cout<<-1,exit(0);
	t=c,c=d;
	exgcd(a,b);
	x*=(t/c),y*=(t/c);
	cout<<x<<" "<<y;
    return 0;
}