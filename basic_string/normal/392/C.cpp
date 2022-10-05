#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=43;
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;
	return r;
}
struct C{
	int a,b;
	C(int x=0,int y=0):a(x),b(y){}
	C operator+(C x){return C((a+x.a)%P,(b+x.b)%P);}
	C operator-(C x){return C((a-x.a)%P,(b-x.b)%P);}
	C operator*(C x){return C((a*1ll*x.a+b*5ll*x.b)%P,(a*1ll*x.b+b*1ll*x.a)%P);}
	C operator~(){int p=qp((a*1ll*a-b*5ll*b)%P,P-2);return C(a*1ll*p%P,-b*1ll*p%P);}
};
int p[N/2],n,m;
C g[N],pw[N],jc[N],ijc[N],pr[N],sf[N];
bool b[N];
long long n2;
C qp(C a,long long b){
	C r=1;
	for(;b;b>>=1,a=a*a)if(b&1)r=r*a;
	return r;
}
void in(int n){
	int i,j,k,t=0;
	for(pw[1]=1,i=2;i<=n;++i){
		if(!b[i])p[++t]=i,pw[i]=qp(i,m);
		for(j=1;j<=t&&(k=i*p[j])<=n;++j){
			b[k]=1,pw[k]=pw[i]*pw[p[j]];
			if(i%p[j]==0)break;
		}
	}
	for(jc[0]=i=1;i<=n;++i)jc[i]=jc[i-1]*i;
	for(ijc[n]=~jc[n],i=n;i;--i)ijc[i-1]=ijc[i]*i;
}
C F(int n,int m){return jc[n]*ijc[m]*ijc[n-m];}
C get(C a){
	int i;
	C ia,ans=0,w=0;
	for(ia=~a,g[0]=0,i=1;i<=m;++i)g[i]=(g[i-1]*ia+pw[i]);
	for(i=0;i<=m;++i)w=w+g[i]*F(m,i)*((m-i&1)?-1:1);
	for(g[0]=C()-w*~qp(ia-1,m),i=1;i<=m;++i)g[i]=g[i-1]*ia+pw[i];
	for(pr[0]=sf[m+1]=i=1;i<=m;++i)pr[i]=pr[i-1]*(n-i);
	for(i=m;i;--i)sf[i]=sf[i+1]*(n-i);
	for(i=1;i<=m;++i)ans=ans+g[i]*pr[i-1]*sf[i+1]*ijc[i-1]*ijc[m-i]*((m-i&1)?-1:1);
	return qp(a,n2)*ans-g[0];
}
int main(){
	scanf("%lld%d",&n2,&m),n=n2%P,in(m+2),++m;
	C a=C(P+1>>1,P+1>>1),b=(P+1>>1,P-(P+1>>1));
	cout<<((get(a)*a-get(b)*b).b*2ll%P+P)%P;
	return 0;
}