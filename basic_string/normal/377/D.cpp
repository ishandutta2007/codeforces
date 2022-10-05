#include<bits/stdc++.h>
using namespace std;
const int N=100009,M=300009;
struct P{
	int l,r,v,id;
}p[N],q[N];
inline bool cmp1(P a,P b){
	return a.l>b.l;
}
inline bool cmp2(P a,P b){
	return a.v>b.v;
}
int s[M<<2],t[M<<2],u,v,w;
void upd(int k,int l,int r){
	if(u<=l&&r<=v){
		s[k]+=w,t[k]+=w;
		return;
	}
	int m=l+r>>1,a=k<<1,b=a|1;
	if(t[k]){
		s[a]+=t[k],t[a]+=t[k];
		s[b]+=t[k],t[b]+=t[k];
		t[k]=0;
	}
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	s[k]=s[a]>s[b]?s[a]:s[b];
}
void getans(int k,int l,int r){
	if(l==r){
		u=l;
		return;
	}
	int m=l+r>>1,a=k<<1,b=a|1;
	if(t[k]){
		s[a]+=t[k],t[a]+=t[k];
		s[b]+=t[k],t[b]+=t[k];
		t[k]=0;
	}
	if(s[k]==s[a])getans(a,l,m);
	else getans(b,m+1,r);
}
bool f[N];
int a[N];
int main(){
	int n,i,j=1,ans=0,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i)p[i].id=i,scanf("%d%d%d",&p[i].l,&p[i].v,&p[i].r),q[i]=p[i];
	sort(p+1,p+n+1,cmp1),sort(q+1,q+n+1,cmp2);
	for(i=1;i<=n;++i){
		while(q[j].v>=p[i].l)u=q[j].v,v=q[j++].r,w=1,upd(1,1,M);
		if(ans<s[1])ans=s[1],k=i;
		u=p[i].v,v=p[i].r,w=-1,upd(1,1,M);
	}
	printf("%d\n",ans),j=1;
	for(i=1;;++i){
		while(q[j].v>=p[i].l)u=q[j].v,v=q[j++].r,w=1,upd(1,1,M);
		if(i==k)break;
		u=p[i].v,v=p[i].r,w=-1,upd(1,1,M),f[p[i].id]=1;
	}
	getans(1,1,M);
	for(i=1,k=0;i<j;++i)if(!f[q[i].id]&&q[i].v<=u&&q[i].r>=u)a[++k]=q[i].id;
	sort(a+1,a+k+1);
	for(i=1;i<=k;++i)printf("%d ",a[i]);
	return 0;
}