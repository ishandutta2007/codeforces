#include<bits/stdc++.h>
using namespace std;
enum{N=1509,S=N-1,T=N-2,M=1128009,O=10000009};
int he[N],to[M],t=1,d[N],q[N],cur[N],ne[M],len[M];
bool bfs(){
	int h=0,t=1,i,j,k;
	memset(d,0,N*4),d[S]=1,q[1]=S;
	while(h<t){
		i=q[++h];
		for(j=he[i];j;j=ne[j])if(len[j]&&!d[k=to[j]])if(d[k]=d[i]+1,q[++t]=k,k==T)return 1;
	}
	return 0;
}
int dfs(int x,int y){
	if(x==T)return y;
	int&i=cur[x],j,u=0,w;
	for(;i;i=ne[i])if(len[i]&&d[j=to[i]]==d[x]+1)if(w=dfs(j,min(len[i],y-u)),len[i]-=w,len[i^1]+=w,u+=w,u==y)break;
	return u;
}
void add(int x,int y){
	ne[++t]=he[x],to[t]=y,len[t]=1,he[x]=t;
	ne[++t]=he[y],to[t]=x,he[y]=t;
}
char s[O];
int c[O][2],f[O],fa[O],qu[O],id,ed[O],p[N],tmp[O];
bitset<N>e[N],vis;
void get(int x){
	vis[x]=1;
	for(int i=he[x];i;i=ne[i])if(to[i]!=S&&!vis[to[i]]){
		vis[to[i]]=1;
		for(int j=he[to[i]];j;j=ne[j])if(len[j])get(to[j]);
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,i,j,l,x,h=0,t=0;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>s,l=strlen(s);
		for(j=x=0;j<l;++j){
			if(!c[x][s[j]-'a'])c[x][s[j]-'a']=++id,fa[id]=x;
			x=c[x][s[j]-'a'];
		}
		ed[x]=i,p[i]=x;
	}
	for(i=0;i<2;++i)if(c[0][i])qu[++t]=c[0][i];
	while(h<t){
		i=qu[++h],j=f[i];
		for(x=0;x<2;++x)if((l=c[i][x]))qu[++t]=l,f[l]=c[j][x];else c[i][x]=c[j][x];
	}
	for(i=1;i<=n;++i)for(j=p[i];j;j=fa[j]){
		if(ed[j]&&ed[j]!=i)e[i][ed[j]]=1;
		x=f[j],l=0;
		while(x&&!ed[x])tmp[++l]=x,x=f[x];
		for(;l;--l)f[tmp[l]]=x;
		if(f[j]=x,ed[x])e[i][ed[x]]=1;
	}
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(e[j][i])e[j]|=e[i];
	for(i=1;i<=n;++i){
		add(S,i),add(i+n,T);
		for(j=1;j<=n;++j)if(e[i][j])add(i,j+n);
	}
	for(j=n;bfs();j-=dfs(S,1e9))memcpy(cur,he,N*4);
	cout<<j<<'\n';
	for(i=he[S];i;i=ne[i])if(len[i])get(to[i]);
	for(i=1;i<=n;++i)if(vis[i]&&!vis[i+n])cout<<i<<' ';
}