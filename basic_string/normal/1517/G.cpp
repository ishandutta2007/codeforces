#include<bits/stdc++.h>
using namespace std;
enum{N=2009,M=N*4,S=N-1,T=N-2};
using ll=long long;
const ll inf=1e16;
int q[N],he[N],to[M],ne[M],cur[N],d[N],t=1,x[N],y[N],w[N];
map<pair<int,int>,int>mp;
ll len[M];
void add(int x,int y,ll z){
	ne[++t]=he[x],to[t]=y,len[t]=z,he[x]=t;
	ne[++t]=he[y],to[t]=x,he[y]=t;
}
#define wk(u,v) if((l=mp[{(u),(v)}]))add(i+n,l,inf);
bool bfs(){
	int h=0,t=1,i,j,k;
	memset(d,0,N*4),d[S]=1,q[1]=S;
	while(h^t){
		i=q[++h];
		for(j=he[i];j;j=ne[j])if(len[j]&&!d[k=to[j]])d[k]=d[i]+1,q[++t]=k;
	}
	return d[T];
}
ll dfs(int x,ll y){
	if(x==T)return y;
	int&i=cur[x],j;
	ll u=0,w;
	for(;i;i=ne[i])if(len[i]&&d[j=to[i]]==d[x]+1){
		w=dfs(j,min(len[i],y-u)),u+=w,len[i]-=w,len[i^1]+=w;
		if(u==y)break;
	}
	return u;
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	int n,i,j,k,l;
	ll ans=0;
	for(cin>>n,i=1;i<=n;++i)cin>>x[i]>>y[i]>>w[i],mp[{x[i],y[i]}]=i,ans+=w[i];
	for(i=1;i<=n;++i){
		add(i,i+n,w[i]),j=x[i],k=y[i];
		bool a=j&1,b=k&1;
		if(a&&!b){
			add(S,i,inf);
			wk(j-1,k) wk(j+1,k)
		}else if(!a&&!b){
			wk(j,k-1) wk(j,k+1)
		}else if(!a&&b){
			wk(j-1,k) wk(j+1,k)
		}else add(i+n,T,inf);
	}
	while(bfs())memcpy(cur,he,N*4),ans-=dfs(S,inf);
	cout<<ans;
	return 0;
}