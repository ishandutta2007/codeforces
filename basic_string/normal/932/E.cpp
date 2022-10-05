#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int f[5009][5009],fc[5009],ifc[5009];
int main(){
	int n,k,o,i,j;
	scanf("%d%d",&n,&k),o=n-k;
	if(o<0){
		fc[0]=1;
		for(i=1;i<=n;++i)fc[i]=fc[i-1]*1ll*i%P;
		ifc[n]=qp(fc[n],P-2);
		for(i=n;i;--i)ifc[i-1]=ifc[i]*1ll*i%P;
		for(i=1,j=0;i<=n;++i)j=(j+fc[n]*1ll*ifc[i]%P*ifc[n-i]%P*qp(i,k))%P;
		printf("%d",j);
		return 0;
	}
	for(i=0;i<=k;++i)f[i][0]=qp(2,i+o)-1;
	for(i=1;i<=k;++i)for(j=1;j<=i;++j)f[i][j]=(i+o)*1ll*(f[i][j-1]-f[i-1][j-1])%P;
	printf("%d",(f[k][k]+P)%P);
	return 0;
}