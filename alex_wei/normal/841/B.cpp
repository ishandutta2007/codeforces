#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll read()
{
	ll x=0;char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x;
}
ll n,s,a;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		a=read(),s+=a%2;
	if(s)cout<<"First";
	else cout<<"Second";
	return 0;
}