#include<cstdio>
#include<cstring>
int t[200009],s[530009],a[200009],b[200009],n,u,v;
void add(int x){
	for(;x<=n;x+=x&-x)++t[x];
}
int sum(int x){
	int r=0;
	for(;x;x-=x&-x)r+=t[x];
	return r;
}
void build(int k,int l,int r){
	if(l==r){
		s[k]=1;
		return;
	}
	int m=l+r>>1,a=k<<1,b=a|1;
	build(a,l,m),build(b,m+1,r),s[k]=s[a]+s[b];
}
void qry(int k,int l,int r){
	--s[k];
	if(l==r){
		v=l;
		return;
	}
	int a=k<<1;
	if(u<s[a])return qry(a,l,l+r>>1);
	return u-=s[a],qry(a|1,(l+r>>1)+1,r);
}
int main(){
	int i;
	scanf("%d",&n); 
	for(i=n;i;--i)scanf("%d",a+i);
	for(i=1;i<=n;++i)b[i]=sum(a[i]),add(a[i]+1);
	memset(t,0,sizeof(t));
	for(i=n;i;--i)scanf("%d",a+i);
	for(i=1;i<=n;++i){
		b[i]+=sum(a[i]),add(a[i]+1);
		if(b[i]>=i)b[i]-=i,++b[i+1];
	}
	build(1,0,n-1);
	for(i=n;i;--i)u=b[i],qry(1,0,n-1),printf("%d ",v);
	return 0;
}