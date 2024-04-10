#include<bits/stdc++.h>
using namespace std;
enum{N=5999,M=59999};
int S=N-1,T=N-2,he[N],to[M],len[M],ne[M],cur[N],co[M],t=1,d[N];
queue<int>q;
bool b[N];
bool spfa(){
	int i,j,k,l;
	for(q.push(S),memset(d,63,N*4),d[S]=0;q.size();)for(i=q.front(),q.pop(),b[i]=0,j=he[i];j;j=ne[j])
	if(len[j]&&d[k=to[j]]>(l=d[i]+co[j]))if(d[k]=l,!b[k])b[k]=1,q.push(k);
	return d[T]<1e9;
}
int dfs(int x,int y){
	if(x==T)return y;
	int&i=cur[x],j,u=0,w;
	for(b[x]=1;i;i=ne[i])if(len[i]&&!b[j=to[i]]&&d[j]==d[x]+co[i])
	if(w=dfs(j,min(y-u,len[i])),len[i]-=w,len[i^1]+=w,u+=w,u==y)break;
	return b[x]=0,u;
}
void add(int i,int j,int k=1,int l=0){
	ne[++t]=he[i],to[t]=j,len[t]=k,co[t]=l,he[i]=t;
	ne[++t]=he[j],to[t]=i,co[t]=-l,he[j]=t;
}
int e[109][109],p[109][109];
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,id,i,j,k,ans;
	cin>>n>>m,id=n,ans=n*(n-1)*(n-2)/6;
	while(m--)cin>>i>>j,++d[j],e[i][j]=1,e[j][i]=-1;
	for(i=1;i<=n;++i)for(j=i+1;j<=n;++j)if(!e[i][j]){
		p[i][j]=++id,add(S,id),add(id,i),add(id,j);
	}
	for(i=1;i<=n;++i){
		ans-=d[i]*(d[i]-1)/2;
		for(j=d[i];j<=n;++j)add(i,T,1,j);
	}
	while(spfa())memcpy(cur,he,N*4),k=dfs(S,1e9),ans-=k*d[T];
	for(i=1;i<=n;cout<<'\n',++i)for(j=1;j<=n;++j)if(i==j)cout<<0;
	else if(e[i][j]){if(e[i][j]==1)cout<<1;else cout<<0;}else if(i<j){
		for(k=he[p[i][j]];k;k=ne[k])if(!len[k]){p[j][i]=((to[k]==i)?0:1);}
		cout<<p[j][i];
	}else cout<<(!p[i][j]);
}