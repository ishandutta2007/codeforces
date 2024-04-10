#include<cstdio>
#include<cstring>
const int N=209,M=2009;
int S,T,g=1,h,he[N],to[M],fl[M],ne[M],len[M],ps[N],Ne[M],To[M],Len[M],He[N],pp[N],cl[N],cur[N],d[N],q[N],id;
bool f[M];
bool bfs(){
	int i,j,k,h=0,t=1;
	memset(d,0,sizeof(d)),d[S]=1,q[1]=S;
	while(h!=t){
		i=q[++h];
		for(j=he[i];j;j=ne[j]){
			k=to[j];
			if(len[j]&&!d[k])d[k]=d[i]+1,q[++t]=k;
		}
	}
	return d[T];
}
int dfs(int x,int y){
	if(x==T||!y)return y;
	int u=0,w,&j=cur[x],k;
	for(;j;j=ne[j]){
		k=to[j];
		if(len[j]&&d[k]>d[x]){
			w=dfs(k,y-u<len[j]?y-u:len[j]),u+=w,len[j]-=w,len[j^1]+=w;
			if(u==y)return u;
		}
	}
	return u;
}
void color(int x){
	cl[x]=id;
	for(int i=he[x];i;i=ne[i])if(len[i]&&cl[to[i]]!=id)color(to[i]);
}
void build(int l,int r){
	if(l==r)return;
	S=ps[l],T=ps[l+1],memcpy(len,fl,sizeof(fl));
	int p=l-1,q=r+1,i=0;
	while(bfs())memcpy(cur,he,sizeof(he)),i+=dfs(S,1e9);
	++id,color(S),h+=i;
	Ne[++g]=He[S],To[g]=T,Len[g]=i,He[S]=g;
	Ne[++g]=He[T],To[g]=S,Len[g]=i,He[T]=g;
	for(i=l;i<=r;++i)if(cl[ps[i]]==id)pp[++p]=ps[i];else pp[--q]=ps[i];
	memcpy(ps+l,pp+l,sizeof(int[r-l+1])),build(l,p),build(q,r);
}
void find(int x,int y){
	for(int i=He[x];i;i=Ne[i]){
		if(To[i]!=y&&!f[i]){
			if(Len[i]<g)g=Len[i],S=x,T=To[i],h=i;
			find(To[i],x);
		}
	}
}
void get(int x){
	g=1e9,find(x,0);
	if(g>1e8)ps[++id]=x;
	else{
		int p=T;
		f[h]=f[h^1]=1,get(S),get(p);
	}
}
int main(){
	int n,m,i,j,k,t=1;
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%d",&i,&j,&k);
		ne[++t]=he[i],to[t]=j,fl[t]=k,he[i]=t;
		ne[++t]=he[j],to[t]=i,fl[t]=k,he[j]=t;
	}
	for(i=1;i<=n;++i)ps[i]=i;
	build(1,n),printf("%d\n",h),id=0,get(1);
	for(i=1;i<=n;++i)printf("%d ",ps[i]);
	return 0;
}