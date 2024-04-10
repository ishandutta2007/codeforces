#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+3;
ll a[N];
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	int n,m,i,j,k;
	ll s,b;
	scanf("%d%d",&n,&m);
	if(n==1){
		scanf("%lld",a+1);
		while(m--){
			scanf("%lld",&b);
			printf("%lld ",a[1]+b);
		}
		return 0;
	}
	for(i=1;i<=n;++i)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	s=a[2]-a[1];
	for(i=2;i<n;++i)s=gcd(s,a[i+1]-a[i]);
	while(m--){
		scanf("%lld",&b);
		printf("%lld ",gcd(a[1]+b,s));
	}
	return 0;
}