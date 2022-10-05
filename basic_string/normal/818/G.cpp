#include<bits/stdc++.h>
using namespace std;
const int N=20009,S=N-2,T=N-1,O=N-3,M=1e5+3;
int he[N],cur[N],to[M],ne[M],len[M],co[M],d[N],t=1,a[N];
queue<int>q;
bool f[N];
void add(int x,int y,int z=4,int w=0){
	ne[++t]=he[x],to[t]=y,len[t]=z,co[t]=w,he[x]=t;
	ne[++t]=he[y],to[t]=x,co[t]=-w,he[y]=t;
}
bool spfa(){
	int i,j,k,l;
	memset(d,-9,N*4),d[S]=0,f[S]=1,q.push(S);
	while(!q.empty()){
		i=q.front(),q.pop(),f[i]=0;
		for(j=he[i];j;j=ne[j])if(len[j]&&d[k=to[j]]<(l=d[i]+co[j]))if(d[k]=l,!f[k])f[k]=1,q.push(k);
	}
	return d[T]>=0;
}
int dfs(int x,int y){
	if(x==T)return y;
	int&i=cur[x],j,u=0,w;
	for(f[x]=1;i;i=ne[i])if(len[i]&&d[j=to[i]]==d[x]+co[i]&&!f[j]){
		w=dfs(j,min(len[i],y-u)),u+=w,len[i]-=w,len[i^1]+=w;
		if(u==y)break;
	}
	return f[x]=0,u;
}
int main(){
	int n,i,j,s=0;
	scanf("%d",&n),add(S,O);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i){
		add(O,i),add(i,i+n,1,1),add(i+n*2,i),add(i+n*3,i),add(i+n,T);
		for(j=i+1;j<=n;++j)if(a[j]==a[i]-1){add(i+n,j+n*2);break;}
		for(j=i+1;j<=n;++j)if(a[j]==a[i]+1){add(i+n,j+n*2);break;}
		for(j=i+1;j<=n;++j)if(a[j]%7==a[i]%7){add(i+n,j+n*3),add(i+n*3,j+n*3);break;}
		for(j=i+1;j<=n;++j)if(a[j]==a[i]){add(i+n*2,j+n*2);break;}
	}
	while(spfa())memcpy(cur,he,N*4),s+=dfs(S,1e9)*d[T];
	printf("%d",s);
	return 0;
}