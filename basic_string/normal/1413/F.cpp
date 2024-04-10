#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3,M=1e6+3,O=15e5+3,P=42e5+3;
int he[N],x[N],y[N],to[M],ne[M],p[N],ed[N],a[O],id,u,v;
bool c[N],len[M],t[P];
void dfs(int x,int y){
	++id,a[++id]=x,p[x]=id;
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y)c[j]=c[x]^len[i],dfs(j,x);
	ed[x]=id,a[++id]=-1;
}
struct T{
	int d,a,b,l1,l2,r1,r2;
};
struct S{
	T a,b;
}s[P];
void get(T&k,int x,bool f){
	k.d=-1,k.l1=k.l2=k.r1=k.r2=-1e9,k.a=k.b=0;
	if(a[x]==0)k.b=1;else if(a[x]==-1)k.a=1;
	else if(c[a[x]]^f)k.l1=k.l2=k.r1=k.r2=k.d=0;
}
void mg(T&k,T&a,T&b){
	if(a.b>b.a)k.a=a.a,k.b=a.b-b.a+b.b;
	else k.a=a.a-a.b+b.a,k.b=b.b;
	k.d=max(max(a.d,b.d),max(a.r2+b.l1,a.r1+b.l2));
	k.l1=max(a.l1,max(b.l1+a.a-a.b,b.l2+a.a+a.b));
	k.l2=max(a.l2,b.l2+a.b-a.a);
	k.r1=max(b.r1,max(a.r1+b.b-b.a,a.r2+b.a+b.b));
	k.r2=max(b.r2,a.r2+b.a-b.b);
}
void build(int k,int l,int r){
	if(l==r)return get(s[k].a,l,1),get(s[k].b,l,0);
	int m=l+r>>1,a=k*2,b=a+1;
	build(a,l,m),build(b,m+1,r),mg(s[k].a,s[a].a,s[b].a),mg(s[k].b,s[a].b,s[b].b);
}
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return t[k]^=1,swap(s[k].a,s[k].b);
	int m=l+r>>1,a=k*2,b=a+1;
	if(t[k])swap(s[a].a,s[a].b),swap(s[b].a,s[b].b),t[a]^=1,t[b]^=1,t[k]=0;
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	mg(s[k].a,s[a].a,s[b].a),mg(s[k].b,s[a].b,s[b].b);
}
int main(){
	int n,m,i,j,k,l,t=0;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d%d",&j,&k,&l),x[i]=j,y[i]=k;
		ne[++t]=he[j],to[t]=k,len[t]=l,he[j]=t;
		ne[++t]=he[k],to[t]=j,len[t]=l,he[k]=t;
	}
	dfs(1,0),build(1,1,id);
	scanf("%d",&m);
	while(m--){
		scanf("%d",&i);
		if(p[x[i]]<p[y[i]])u=p[y[i]],v=ed[y[i]];else u=p[x[i]],v=ed[x[i]];
		upd(1,1,id),printf("%d\n",max(s[1].a.d,s[1].b.d));
	}
	return 0;
}