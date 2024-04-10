#include<cstdio>
#include<queue>
#include<cstring>
using std::queue;
const int N=1009,M=5009,P=10009;
int t,n,u[M],v[M],He[N],Ne[M],he[N],to[P],len[P],ne[P],d[N],cnt[N];
bool f[N],g[N],h[N],w[M];
queue<int>q;
bool dfs(int x){
	if(x==n||f[x])return 1;
	if(h[x])return 0;
	register bool b=0;
	g[x]=1;
	for(register int i=He[x],j;i;i=Ne[i]){
		j=v[i];
		if(!g[j]&&dfs(j))w[i]=1,ne[++t]=he[x],to[t]=j,len[t]=2,he[x]=t,ne[++t]=he[j],to[t]=x,len[t]=-1,he[j]=t,b=1;
	}
	g[x]=0,h[x]=1;
	return f[x]=b;
}
int main(){
	register int m,i,j,k,l;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",u+i,v+i),Ne[i]=He[u[i]],He[u[i]]=i;
	if(!dfs(1))return puts("-1"),0;
	memset(f,0,sizeof(f)),memset(d,63,sizeof(d)),d[1]=0,f[1]=1,q.push(1);
	while(!q.empty()){
		i=q.front(),q.pop(),f[i]=0;
		for(j=he[i];j;j=ne[j]){
			k=to[j],l=len[j]+d[i];
			if(d[k]>l){
				d[k]=l,cnt[k]=cnt[i]+1;
				if(cnt[k]>n)return puts("No"),0;
				if(!f[k])f[k]=1,q.push(k);
			}
		}
	}
	puts("Yes");
	for(i=1;i<=m;++i)printf("%d\n",w[i]?(d[v[i]]-d[u[i]]):1);
	return 0;
}