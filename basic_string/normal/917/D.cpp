#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll P=1e9+7,N=107;
ll a[N][N],b[N][N];
int n;
bool e[N][N];
ll qp(ll a,ll b){
	ll r=1;
	for(;b;a=a*a%P,b>>=1)if(b&1)r=r*a%P;
	return r;
}
ll mattree(int g){
	int i,j,k;
	ll s=1,v,w;
	memset(a,0,sizeof(a));
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(i!=j)k=e[i][j]?g:1,(a[i][j]-=k)%=P,(a[i][i]+=k)%=P;
	for(i=1;i<n;++i){
		v=qp(a[i][i],P-2);
		for(j=i+1;j<n;++j){
			w=a[j][i]*v%P;
			for(k=i;k<=n;++k)(a[j][k]-=a[i][k]*w)%=P;
		}
		s=s*a[i][i]%P;
	}
	return(s+P)%P;
}
int main(){
	int i,j,k;
	ll v,w;
	scanf("%d",&n);
	for(i=1;i<n;++i)scanf("%d%d",&j,&k),e[j][k]=e[k][j]=1;
	for(i=0;i<n;++i){
		b[i][0]=w=1,b[i][n]=mattree(i+1);
		for(j=1;j<n;++j)w=w*(i+1)%P,b[i][j]=w;
	}
	for(i=0;i<n;++i){
		v=qp(b[i][i],P-2);
		for(j=0;j<n;++j)if(j!=i){
			w=b[j][i]*v%P;
			for(k=i+1;k<=n;++k)(b[j][k]-=b[i][k]*w)%=P;
		}
	}
	for(i=0;i<n;++i)printf("%lld ",(b[i][n]*qp(b[i][i],P-2)%P+P)%P);
	return 0;
}