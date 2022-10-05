#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m),printf("%lld",qp(2*(n+1),m-1)*2ll*(n+1-m)%P);
	return 0;
}