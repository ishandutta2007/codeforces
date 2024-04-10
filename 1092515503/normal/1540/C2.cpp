#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7; 
int n,q,c[110],C[110],b[110],B[110],L=0x3f3f3f3f,R=0xc0c0c0c0;
int f[10100],g[1010];
int DP(int x){
	memset(f,0,sizeof(f));
	f[0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<min(B[i]+i*x,C[i]+1);j++)f[j]=0;
		for(int j=C[i];j>=max(B[i]+i*x,0);j--)(f[j+c[i+1]+1]+=mod-f[j])%=mod;
		for(int j=max(B[i]+i*x,0);j<=C[i+1];j++)(f[j+1]+=f[j])%=mod;
	}
	int ret=0;
	for(int j=max(B[n]+n*x,0);j<=C[n];j++)(ret+=f[j])%=mod;
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]),C[i]=C[i-1]+c[i];
	for(int i=1;i<n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)for(int k=1;k<j;k++)B[i]+=b[k];
//	for(int i=1;i<=n;i++)printf("%d ",C[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",B[i]);puts("");
	for(int i=1;i<=n;i++)L=min(L,-B[i]/i-10),R=max(R,(C[i]-B[i])/i+10);
//	printf("<%d,%d>\n",L,R);
	for(int i=L;i<=R;i++)g[i-L]=DP(i);
	scanf("%d",&q); 
	for(int i=1,x;i<=q;i++){
		scanf("%d",&x),x=min(x,R),x=max(x,L);
		printf("%d\n",g[x-L]);
	}
	return 0;
}