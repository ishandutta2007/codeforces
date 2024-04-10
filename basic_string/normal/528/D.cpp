#include<cstdio>
#include<cstring>
const int P=998244353;
int qp(int a,int b){
	int r=1;
	for(;b;a=a*1ll*a%P,b>>=1)if(b&1)r=r*1ll*a%P;
	return r;
}
const int N=2e5+9,M=530009,ig=qp(3,P-2);
int a[M],b[M],r[M],c[N],li=1,n,m,k;
char s[N],t[N];
void ntt(int*a,bool b){
	int i,j,k,l,p,u,v,x,y;
	for(i=0;i<li;++i)if(i<r[i])j=a[i],a[i]=a[r[i]],a[r[i]]=j;
	for(i=1;i<li;i<<=1)
	for(l=i<<1,u=qp(b?3:ig,(P-1)/l),j=0;j<li;j+=l)
	for(v=1,k=j,p=j+i;k<p;++k,v=v*1ll*u%P)
	x=a[k],y=v*1ll*a[k+i]%P,a[k]=(a[k]=x+y)<P?a[k]:a[k]-P,a[k+i]=x<y?x-y+P:x-y;
}
void get(char x){
	int i,j;
	memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
	for(i=0,j=-1e7;i<n;++i){
		if(s[i]==x)j=i;
		if(i-j<=k)a[i]=1;
	}
	for(i=n-1,j=1e7;i>=0;--i){
		if(s[i]==x)j=i;
		if(j-i<=k)a[i]=1;
	}
	for(i=0;i<m;++i)b[i]=t[m-i-1]==x;
	ntt(a,1),ntt(b,1);
	for(i=0;i<li;++i)a[i]=a[i]*1ll*b[i]%P;
	ntt(a,0);
	for(i=m-1,j=qp(li,P-2);i<n;++i)c[i]+=a[i]*1ll*j%P;
}
int main(){
	int i,j=-1;
	scanf("%d%d%d%s%s",&n,&m,&k,s,t);
	while(li<=n+m)li<<=1,++j;
	for(i=0;i<li;++i)r[i]=(r[i>>1]>>1)|((i&1)<<j);
	get('A'),get('G'),get('T'),get('C');
	for(i=m-1,j=0;i<n;++i)j+=c[i]==m;
	printf("%d",j);
	return 0;
}