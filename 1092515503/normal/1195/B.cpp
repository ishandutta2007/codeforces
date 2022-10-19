#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,tot;
ll rt(ll ip){
	return sqrt(ip);
}
int main(){
	scanf("%I64d%I64d",&n,&k);
	tot=n*(n+1)/2;tot-=k;
	printf("%I64d\n",(2*n+3-rt((2*n+3)*(2*n+3)-tot*8))/2);
	return 0;
}