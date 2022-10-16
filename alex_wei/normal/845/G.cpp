#include<bits/stdc++.h>
using namespace std;

#define db double
#define ll long long
#define ld long double
#define ull unsigned long long

#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mem(x,v,s) memset(x,v,sizeof(x[0])*(s))
#define cpy(x,y,s) memcpy(x,y,sizeof(x[0])*(s))

const int L=30;
const int N=1e5+5;

int n,m,a[L];
int minxor(int res){
	for(int i=29;~i;i--)
		if((res^a[i])<res)
			res^=a[i];
	return res;
}
void insert(int x){
	for(int i=29;~i;i--)
		if(x>>i&1){
			if(a[i]){x^=a[i]; continue;}
			for(int j=i-1;~j;j--)if(x>>j&1)x^=a[j];
			for(int j=i+1;j<30;j++)if(a[j]>>i&1)a[j]^=x;
			return a[i]=x,void();
		}
}

int cnt,hd[N],nxt[N<<1],to[N<<1],val[N<<1];
void add(int u,int v,int w){
	nxt[++cnt]=hd[u],hd[u]=cnt;
	to[cnt]=v,val[cnt]=w;
}

int vis[N],cur[N];
void dfs(int id,int w){
	vis[id]=1,cur[id]=w;
	for(int i=hd[id];i;i=nxt[i])
		if(vis[to[i]])insert(cur[to[i]]^w^val[i]);
		else dfs(to[i],w^val[i]);
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w; cin>>u>>v>>w;
		add(u,v,w),add(v,u,w);
	} dfs(1,0),cout<<minxor(cur[n])<<endl;
	return 0;
}
//////