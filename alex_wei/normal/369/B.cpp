#include<bits/stdc++.h>
using namespace std;
int n,k,l,r,sa,sk,d,m,d2,m2;
int main()
{
	cin>>n>>k>>l>>r>>sa>>sk;
	if(n==1)cout<<sk,exit(0);
	sa-=sk; d2=sk/k,m2=sk%k;
	if(n>k)d=sa/(n-k),m=sa%(n-k);
	for(int i=1;i<=n;i++)
		if(i<=k)cout<<d2+(m2>0)<<" ",m2--;
		else cout<<d+(m>0)<<" ",m--;
    return 0;
}