#include<bits/stdc++.h>
using namespace std;
#define ll long long
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int n,m[1003][1003];
ll a[1003],mu=1;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>m[i][j];
	a[1]=1;
	for(int i=2;i<=n;i++)
		a[i]=m[1][i];
	for(int i=3;i<=n;i++){
		a[i]/=mu;
		ll mut=a[i-1]*a[i];
		ll k=sqrt(mut/m[i-1][i]);
		a[1]*=k,a[i]/=k,a[i-1]/=k;
		mu*=k;
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
    return 0;
}