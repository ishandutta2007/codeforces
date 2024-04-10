#include<bits/stdc++.h>
using namespace std;
const int N=607,M=181207;
int T,he[N],to[M],len[M],ne[M],cur[N],q[N],d[N],t=1;
void add(int x,int y,int z){
	ne[++t]=he[x],to[t]=y,len[t]=z,he[x]=t;
	ne[++t]=he[y],to[t]=x,he[y]=t;
}
bool bfs(){
	int h=0,t=1,i,j,k;
	memset(d,0,N*4),d[0]=1,q[1]=0;
	while(h!=t)for(j=he[i=q[++h]];j;j=ne[j])if(len[j]&&!d[k=to[j]])q[++t]=k,d[k]=d[i]+1;
	return d[T];
}
int dfs(int x,int y){
	if(x==T||!y)return y;
	int u=0,w,&j=cur[x],k;
	for(;j;j=ne[j])if(len[j]&&d[k=to[j]]>d[x])if(w=dfs(k,min(len[j],y-u)),len[j]-=w,len[j^1]+=w,u+=w,u==y)return u;
	return u;
}
int main(){
	long long ans=0;
	int n,i,j,k;
	cin>>n,T=n*2+1;
	for(i=1;i<=n;++i)for(cin>>j;j--;)cin>>k,add(i,k+n,1e9);
	for(i=1;i<=n;++i)cin>>j,add(0,i,k=4e8-j),add(i+n,T,4e8),ans-=k;
	while(bfs())memcpy(cur,he,N*4),ans+=dfs(0,1e9);
	cout<<ans;
	return 0;
}