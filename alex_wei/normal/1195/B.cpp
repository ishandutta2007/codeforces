#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long n,k;
int main()
{
	cin>>n>>k;
	for(ll i=0;i<=100000000;i++){
		ll eat=n-i,rem=i;
		if(rem*(rem+1)/2-eat==k)
			cout<<eat,exit(0);
	}
    return 0;
}