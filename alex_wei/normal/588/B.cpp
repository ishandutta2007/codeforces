#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,ans=1;
int main()
{
	cin>>a;
	for(ll i=2;i<=sqrt(a);i++)
		if(a%i==0){ans*=i;while(a%i==0)a/=i;}
	cout<<ans*a;
	return 0;
}