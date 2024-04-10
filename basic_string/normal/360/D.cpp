#include<bits/stdc++.h>
using namespace std;
const int N=10009;
int a[N],n,m,p,w[19],to[N],f[N];
bool b[N];
unordered_map<int,int>mp;
int qp(int a,int b){
	int r=1;
	for(;b;b>>=1,a=a*1ll*a%p)if(b&1)r=r*1ll*a%p;
	return r;
}
int main(){
	int i,j,k,l,o,p,id=0,t=0;
	long long ans=0;
	scanf("%d%d%d",&n,&m,&::p),p=::p-1;
	for(i=1;i*i<p;++i)if(p%i==0)to[++id]=i,to[++id]=p/i;
	if(i*i==p)to[++id]=i;
	sort(to+1,to+id+1);
	for(i=1;i<=id;++i)mp[to[i]]=i;
	for(i=2,j=p;i*i<=j;++i)if(j%i==0)for(w[++t]=i;j/=i,j%i==0;);
	if(j>1)w[++t]=j;
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(scanf("%d",&j);--m;)scanf("%d",&i),j=gcd(j,i);
	for(i=1;i<=n;++i){
		k=qp(a[i],j);
		for(l=1,o=p;l<=t;++l)while(o%w[l]==0&&qp(k,o/w[l])==1)o/=w[l];
		b[mp[o]]=1;
	}
	for(i=id;i;--i)if(b[i]){
		k=1-f[i],ans+=k*to[i];
		for(j=i-1;j;--j)if(to[i]%to[j]==0)b[j]=1,f[j]+=k;
	}
	printf("%lld",ans);
	return 0;
}