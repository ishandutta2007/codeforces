#include<bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long

#define pii pair <int, int>
#define fi first
#define se second
#define pb push_back
#define mem(x, v, s) memset(x, v, sizeof(x[0]) * (s))
#define cpy(x, y, s) memcpy(x, y, sizeof(x[0]) * (s))

#define gc getchar()
inline int read(){
	int x=0,sign=0; char s=gc;
	while(!isdigit(s))sign|=s=='-',s=gc;
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
	return sign?-x:x;
}
////////////////////
const int N=2e5+5;
const int K=18;

int n,m,k,u[N],v[N],ind[N],col[N],buc[N<<1];
int cnt=1,hd[N<<1],nxt[N<<1],to[N<<1];
void add(int u,int v){nxt[++cnt]=hd[u],hd[u]=cnt,to[cnt]=v;}

int vis[N],fa[N][K],dep[N];
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=k;~i;i--)
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=k;~i;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dfs(int id,int f){
	vis[id]=1,fa[id][0]=f,dep[id]=dep[f]+1;
	col[id]=col[f]^1;
	for(int i=hd[id];i;i=nxt[i]){
		int it=to[i];
		if(vis[it]||it==f)continue;
		buc[i]=buc[i^1]=1,dfs(it,id);
	}
}

int cf[N];
void dfs2(int id,int f){
	vis[id]=1;
	for(int i=hd[id];i;i=nxt[i]){
		int it=to[i];
		if(buc[i]&&it!=f)dfs2(it,id),cf[id]+=cf[it];
	}
}
int main(){
	cin>>n>>m,k=log2(n);
	for(int i=1;i<=m;i++){
		u[i]=read(),v[i]=read(),ind[i]=cnt+1;
		add(u[i],v[i]),add(v[i],u[i]);
	}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
//	for(int i=1;i<=n;i++)cout<<"col "<<col[i]<<endl;
	for(int j=1;j<=k;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	int cnt=0;
	for(int i=1;i<=m;i++)cnt+=(col[u[i]]^col[v[i]])==0;
	if(cnt==0){
		cout<<m<<endl;
		for(int i=1;i<=m;i++)cout<<i<<" ";
		cout<<endl,exit(0);
	}
	vector <int> ans;
	for(int i=1;i<=m;i++){
		if(buc[ind[i]])continue;
		int d=LCA(u[i],v[i]);
//		cout<<"add "<<u[i]<<" "<<v[i]<<" "<<d<<" "<<(col[u[i]]^col[v[i]])<<endl;
		if(col[u[i]]^col[v[i]])cf[u[i]]--,cf[v[i]]--,cf[d]+=2;
		else cf[u[i]]++,cf[v[i]]++,cf[d]-=2;
	}
	mem(vis,0,N);
	for(int i=1;i<=m;i++)if(!vis[i])dfs2(i,0);
	for(int i=1;i<=m;i++){
		if(buc[ind[i]]){
			if(dep[u[i]]<dep[v[i]])swap(u[i],v[i]);
			if(cf[u[i]]==cnt)ans.pb(i);
		} else if(!(col[u[i]]^col[v[i]])&&cnt==1)
			ans.pb(i);
	}
	cout<<ans.size()<<endl;
	for(int it:ans)cout<<it<<" ";
	cout<<endl;
	return 0;
}