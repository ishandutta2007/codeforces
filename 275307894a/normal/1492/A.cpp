#include<cstdio>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
long long t,a,b,n,m;
inline long long ceil(long long x,long long y){return x/y+(x%y!=0);}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&n,&m,&a,&b);
		printf("%lld\n",min(ceil(n,m)*m,min(ceil(n,a)*a,ceil(n,b)*b))-n);
	}
}