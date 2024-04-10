#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)51*1000)
#define M ((ll)601*1000)

ll n,m;

int main()
{
	cin>>n>>m;
	if(n>m)swap(n,m);
	if(n==1)return cout<<n*m-(m+2)/3,0;
	if(n==2)return cout<<n*m-(m/2)-1,0;
	if(n==3)return cout<<n*m-m/4*3-(m%4)-(m%4==0),0;
	if(n==4)return cout<<n*m-m-(m%4==1 || m==6),0;
	if(n==5 && m==8)return cout<<n*m-11,0;
	if(n==5)return cout<<n*m-m-2,0;
	if(n==6)return cout<<n*m-10,0;
	return 0;
}