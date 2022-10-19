#include<bits/stdc++.h>
using namespace std;
int n,m;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
int main(){
	scanf("%d%d",&n,&m);
	printf("%d\n",1ll*ksm(2,m)*ksm(n+1,m-1)%mod*(n-m+1)%mod);
	return 0;
}