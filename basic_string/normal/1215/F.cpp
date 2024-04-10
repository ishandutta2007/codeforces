#include<bits/stdc++.h>
using namespace std;
const int N=16e5+3,M=4e6+3;
int o,t,he[N],to[M],ne[M],l[N],id,st[N],tp,bl[N],ct,ans[N];
void add(int x,int y){ne[++t]=he[x],to[t]=y,he[x]=t;}
void ins(int x,int y){add(x,y),add(y>o?y-o:y+o,x>o?x-o:x+o);}
void tar(int x){
	int i=he[x],p=++id,j;
	for(l[st[++tp]=x]=p;i;i=ne[i])if(!l[j=to[i]])tar(j),l[x]=min(l[x],l[j]);else if(!bl[j])l[x]=min(l[x],l[j]);
	if(l[x]==p)for(++ct;bl[st[tp]]=ct,st[tp--]!=x;);
}
int main(){
	int a,n,m,b,i,j,k;
	scanf("%d%d%d%d",&a,&n,&m,&b),o=n+m;
	while(a--)scanf("%d%d",&i,&j),ins(i+o,j);
	for(i=1;i<=n;++i)if(scanf("%d%d",&j,&k),ins(i,k+n),--j)ins(i,j+n+o);
	for(add(o*2,o);i<o;++i)ins(i,i+1);
	while(b--)scanf("%d%d",&i,&j),ins(i,j+o);
	for(i=1;i<=2*o;++i)if(!l[i])tar(i);
	for(i=1;i<=o;++i)if(bl[i]==bl[i+o])return puts("-1"),0;
	for(i=1,k=0;i<=n;++i)if(bl[i]<bl[i+o])ans[++k]=i;
	for(;bl[i]>bl[i+o];++i);
	printf("%d %d\n",k,i-n);
	for(i=1;i<=k;++i)printf("%d ",ans[i]);
	return 0;
}