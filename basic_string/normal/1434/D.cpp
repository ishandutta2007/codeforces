#include<bits/stdc++.h>
using namespace std;
const int N=4200003;
int he[N],to[N],ne[N],len[N],s[N],ct,ps[N],ed[N],x[N],y[N],u,v;
bool c[N],tg[N];
void dfs(int x,int y){
	s[++ct]=-1,s[++ct]=x,ps[x]=ct;
	for(int i=he[x],j;i;i=ne[i])if((j=to[i])!=y){
		c[j]=c[x]^len[i],dfs(j,x);
	}
	s[++ct]=-2,ed[x]=ct;
}
struct G{
	int a,b,l1,l2,r1,r2,dis;
};
struct T{
	G a,b;
}t[N];
void push(G&t,int x,bool f){
	t.a=t.b=0;t.l1=t.l2=t.r1=t.r2=t.dis=-1e9;
	if(s[x]==-1)t.b=1;else
	if(s[x]==-2)t.a=1;else
	if(!(c[s[x]]^f))t.l1=t.r1=t.r2=t.l2=0;
}
void mg(G&k,const G&a,const G&b){
	if(a.b>b.a)
	 k.a=a.a,k.b=a.b-b.a+b.b;else
	 k.a=a.a+b.a-a.b,k.b=b.b;
	k.l1=max(a.l1,max(b.l1+a.a-a.b,b.l2+a.a+a.b));
	k.l2=max(a.l2,b.l2-a.a+a.b);
	k.r1=max(b.r1,max(a.r1-b.a+b.b,a.r2+b.a+b.b));
	k.r2=max(b.r2,a.r2+b.a-b.b);
	k.dis=max(max(a.r1+b.l2,a.r2+b.l1),max(a.dis,b.dis));
}
void build(int k,int l,int r){
	if(l==r){
		push(t[k].a,l,0);
		push(t[k].b,l,1);
		return;
	}
	int m=l+r>>1;
	build(k*2,l,m),build(k*2+1,m+1,r);
	mg(t[k].a,t[k*2].a,t[k*2+1].a),mg(t[k].b,t[k*2].b,t[k*2+1].b);
}
void upd(int k,int l,int r){
	if(u<=l&&r<=v){
		swap(t[k].a,t[k].b),tg[k]^=1;
		return;
	}
	int m=l+r>>1,a=k*2,b=k*2+1;
	if(tg[k])swap(t[a].a,t[a].b),swap(t[b].a,t[b].b),tg[a]^=1,tg[b]^=1,tg[k]=0;
	if(u<=m)upd(a,l,m);
	if(m<v)upd(b,m+1,r);
	mg(t[k].a,t[a].a,t[b].a),mg(t[k].b,t[a].b,t[b].b);
}
int main(){
	int n,q,i,j,k,l,t=0;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d%d",&j,&k,&l),x[i]=j,y[i]=k;
		ne[++t]=he[j],to[t]=k,len[t]=l,he[j]=t;
		ne[++t]=he[k],to[t]=j,len[t]=l,he[k]=t;
	}
	dfs(1,0),build(1,1,ct);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&i);
		if(ps[x[i]]>ps[y[i]])j=x[i];else j=y[i];
		u=ps[j]-1,v=ed[j],upd(1,1,ct),printf("%d\n",max(max(::t[1].a.dis,::t[1].b.dis),0));
	}
	return 0;
}