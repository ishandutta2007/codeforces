#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll s(ll x){ll a=0;while(x)a+=x%10,x/=10;return a;}
int main()
{
	cin>>n;
	for(long long i=max((ll)0,(ll)sqrt(n)-81);i<=sqrt(n);i++)
		if(i*i+s(i)*i-n==0)
			cout<<i,exit(0);
	cout<<-1;
    return 0;
}