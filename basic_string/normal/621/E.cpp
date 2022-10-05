#include<bits/stdc++.h>
using namespace std;
const int N=103,P=1e9+7;
int u[N],v[N],w[N],x,o;
void dp(int*a,int*b){
	memset(w,0,x*4);
	int i,j,k;
	for(i=0;i<x;++i)for(j=0,k=i*o%x;j<x;++j,k=(++k)<x?k:k-x)w[k]=(a[i]*1ll*b[j]+w[k])%P;
	memcpy(a,w,x*4);
}
int main(){
	int n,b,k,i,j;
	scanf("%d%d%d%d",&n,&b,&k,&x),o=10%x,v[0]=1;
	while(n--)scanf("%d",&i),++u[i%x];
	for(;b;b>>=1,dp(u,u),o=o*o%x)if(b&1)dp(v,u);
	printf("%d",v[k]);
	return 0;
}