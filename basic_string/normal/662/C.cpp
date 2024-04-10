#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e5+3,N=M*11;
char s[M];
ll a[N],b[N];
int n,pc[N],d[M];
void fwt(ll*a){
	int i,j,k,l,p;
	ll w;
	for(i=1;i<n;i<<=1)
	for(j=0,l=i<<1;j<n;j+=l)
	for(k=j,p=j+i;k<p;++k)
	w=a[i+k],a[i+k]=a[k]-w,a[k]+=w;
}
void ifwt(ll*a){
	int i,j,k,l,p;
	ll w;
	for(i=1;i<n;i<<=1)
	for(j=0,l=i<<1;j<n;j+=l)
	for(k=j,p=j+i;k<p;++k)
	w=a[i+k],a[i+k]=a[k]-w>>1,(a[k]+=w)>>=1;
}
int main(){
	int p,m,i,j;
	ll w=1e9;
	scanf("%d%d",&p,&m),n=1<<p;
	for(i=0;i<p;++i){
		scanf("%s",s);
		for(j=0;j<m;++j)if(s[j]=='1')d[j]|=1<<i;
	}
	for(i=1;i<n;++i)pc[i]=pc[i>>1]+(i&1),b[i]=min(pc[i],p-pc[i]);
	for(i=0;i<m;++i)++a[d[i]];
	fwt(a),fwt(b);
	for(i=0;i<n;++i)a[i]*=b[i];
	ifwt(a);
	for(i=0;i<n;++i)w=min(w,a[i]);
	printf("%lld",w);
	return 0;
}