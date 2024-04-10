#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int ksm(int x,int y=mod-2){
	int z=1;
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;
	return z;
}
int n,m,res;
int main(){
	scanf("%d%d",&n,&m),res=ksm(m,n);
	for(int i=0,j=res,invm=ksm(m),k=1;i<n;i++,j=1ll*j*invm%mod,k=1ll*k*(2*m-1)%mod)(res+=1ll*j*k%mod)%=mod;
	printf("%d\n",res);
	return 0;
}