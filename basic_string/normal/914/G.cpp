#include<bits/stdc++.h>
using namespace std;
const int N=131079,P=1e9+7;
int n=1,h[N],a[21][N],y[N],z[N],p[N],f[N],x[N];
void OR(int*a,int b){
	int i,j,k,l,p;
	for(i=1;i<n;i*=2)
	for(j=0,l=i*2;j<n;j+=l)
	for(k=j,p=j+i;k<p;++k)
	a[i+k]=(a[i+k]+a[k]*b)%P;
}
void AND(int*a,int b){
	int i,j,k,l,p;
	for(i=1;i<n;i*=2)
	for(j=0,l=i*2;j<n;j+=l)
	for(k=j,p=j+i;k<p;++k)
	a[k]=(a[k]+a[i+k]*b)%P;
}
void XOR(int*a,int b){
	int i,j,k,l,p,w;
	for(i=1;i<n;i*=2)
	for(j=0,l=i*2;j<n;j+=l)
	for(k=j,p=j+i;k<p;++k)
	w=a[i+k],a[i+k]=(a[k]-w)*1ll*b%P,a[k]=(a[k]+w)*1ll*b%P;
}
int main(){
	int m,w=0,i,j,k,t=0;
	scanf("%d",&m),f[1]=p[1]=1;
	for(i=0;i<m;++i)scanf("%d",&j),++z[j],w=max(w,j);
	while(n<=w)n<<=1,++t;
	for(i=2;i<n;++i)f[i]=(f[i-1]+f[i-2])%P,p[i]=p[i>>1]+(i&1);
	for(i=0;i<n;++i)a[p[i]][i]=z[i],y[i]=z[i]*1ll*f[i]%P;
	for(i=0;i<=t;++i)OR(a[i],1);
	for(i=0;i<=t;++i){
		memset(h,0,n<<2);
		for(j=0;j<=i;++j)for(k=0;k<n;++k)h[k]=(h[k]+a[j][k]*1ll*a[i-j][k])%P;
		OR(h,-1);
		for(j=0;j<n;++j)if(p[j]==i)x[j]=h[j]*1ll*f[j]%P;
	}
	XOR(z,1);
	for(i=0;i<n;++i)z[i]=z[i]*1ll*z[i]%P;
	XOR(z,P+1>>1);
	for(i=0;i<n;++i)z[i]=z[i]*1ll*f[i]%P;
	AND(x,1),AND(y,1),AND(z,1);
	for(i=0;i<n;++i)x[i]=x[i]*1ll*y[i]%P*z[i]%P;
	AND(x,-1);
	for(i=w=0;i<=t;++i)w=(w+x[1<<i])%P;
	printf("%d",(w+P)%P);
	return 0;
}