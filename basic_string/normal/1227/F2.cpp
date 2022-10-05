#include<bits/stdc++.h>
using namespace std;
const int N=2e5+3,P=998244353;
int fc[N],ifc[N];
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
#define C(x,y) (fc[x]*1ll*ifc[y]%P*ifc[(x)-(y)]%P)
int main(){
	int n,m=0,i,j,k,l,o,s=0;
	scanf("%d%d%d",&n,&k,&o),l=o,fc[0]=1;
	if(n==1)return puts("0"),0;
	for(i=1;i<n;++i)scanf("%d",&j),m+=j!=l,l=j;
	for(i=1,m+=j!=o;i<=m;++i)fc[i]=fc[i-1]*1ll*i%P;
	for(i=m,ifc[m]=qp(fc[m],P-2);i;--i)ifc[i-1]=ifc[i]*1ll*i%P;
	for(i=m/2,o=(k-2)*1ll*(k-2)%P,l=qp(k-2,m-i*2);~i;--i)s=(s+C(m,i)*C(m-i,i)%P*l)%P,l=l*1ll*o%P;
	printf("%lld",((qp(k,m)-s)*1ll*qp(2,P-2)%P*qp(k,n-m)%P+P)%P);
	return 0;
}