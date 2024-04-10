#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=17,M=16389,O=131;
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
int a[N],e[N][N],p[M],n,ll[O][O],lr[O][O],rl[O][O],rr[O][O];
int g(int x,int y){
	int i,j,s=1;
	for(i=0;i<n;++i)if(x>>i&1)for(j=0;j<n;++j)if(y>>j&1)s=s*1ll*e[i][j]%P;
	return s;
}
int h(int x,int y){
	return ll[x&127][y&127]*1ll*lr[x&127][y>>7]%P*rl[x>>7][y&127]%P*rr[x>>7][y>>7]%P;
}
int main(){
	int m,i,j,w=0;
	scanf("%d",&n);
	for(i=0;i<n;++i)scanf("%d",a+i);
	for(i=0;i<n;++i)for(j=0;j<n;++j)e[i][j]=a[i]*1ll*qp(a[i]+a[j],P-2)%P;
	for(i=0;i<O;++i)for(j=0;j<O;++j)ll[i][j]=lr[i][j]=rl[i][j]=rr[i][j]=1;
	for(i=0,m=1<<min(n,7);i<m;++i)for(j=0;j<m;++j)if(!(i&j))ll[i][j]=g(i,j);
	if(n>7){
		for(i=0,m=1<<n-7;i<128;++i)for(j=0;j<m;++j)lr[i][j]=g(i,j<<7);
		for(i=0;i<m;++i)for(j=0;j<128;++j)rl[i][j]=g(i<<7,j);
		for(i=0;i<m;++i)for(j=0;j<m;++j)if(!(i&j))rr[i][j]=g(i<<7,j<<7);
	}
	for(i=1,m=1<<n;i<m;w=(w+p[i]*1ll*h(i,m-1^i)%P*__builtin_popcount(i))%P,++i)for(p[i]=1,j=i&i-1;j;j=j-1&i)p[i]=(p[i]-p[j]*1ll*h(j,i^j))%P;
	printf("%d",(w+P)%P);
	return 0;
}