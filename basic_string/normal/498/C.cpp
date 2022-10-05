#include<bits/stdc++.h>
using namespace std;
const int N=3009,M=9009;
int he[N],cur[N],len[M],to[M],ne[M],d[N],q[N],t=1,id=1,T=2999;
inline void add(int x,int y,int z){
	ne[++t]=he[x],to[t]=y,len[t]=z,he[x]=t;
	ne[++t]=he[y],to[t]=x,he[y]=t;
}
map<int,int>a[109];
int f[13],g[13],o;
void fac(int x){
	for(int i=2;i*i<=x;++i){
		if(!(x%i)){
			f[++o]=i,g[o]=0;
			do x/=i,++g[o];while(!(x%i));
		}
	}
	if(x>1)f[++o]=x,g[o]=1;
}
bool bfs(){
	int h=0,t=1,i,j,k;
	memset(d,0,sizeof(d)),d[1]=q[1]=1;
	while(h!=t){
		i=q[++h];
		for(j=he[i];j;j=ne[j])if(len[j]&&!d[k=to[j]]){
			d[k]=d[i]+1,q[++t]=k;
		}
	}
	return d[T];
}
int dfs(int x,int y){
	if(x==T||!y)return y;
	int u=0,w,&j=cur[x],k;
	for(;j;j=ne[j])if(len[j]&&d[k=to[j]]>d[x]){
		w=dfs(k,min(len[j],y-u)),u+=w,len[j]-=w,len[j^1]+=w;
		if(u==y)return u; 
	}
	return u;
}
int main(){
	int n,m,i,j,k,ans=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&j),o=0,fac(j);
		if(i&1){
			for(k=1;k<=o;++k){
				add(1,++id,1e9),add(id,id+1,g[k]),a[i][f[k]]=++id;
			}
		}else{
			for(k=1;k<=o;++k){
				a[i][f[k]]=++id,add(id,id+1,g[k]),add(++id,T,1e9);
			}
		}
	}
	while(m--){
		scanf("%d%d",&i,&j);
		if(j&1)swap(i,j);
		for(auto u:a[i])if(a[j].count(u.first)){
			add(u.second,a[j][u.first],1e9);
		}
	}
	while(bfs())memcpy(cur,he,sizeof(he)),ans+=dfs(1,2e9);
	printf("%d",ans);
	return 0;
}