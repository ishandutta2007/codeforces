// Author: Alan_boyfriend
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,l,r) for(int i=(l);i>=(r);i--)
#define pb push_back
#define fir first
#define sec second
#define SZ(x) ((int)x.size())
#define pii pair<int,int>
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}

#define N 300005

int a[N],c[N],n;
int s[N],h[N];
int ans[N];

vector<int>adj[N];
void dfs1(int u,int fa){
	vector<int>re;
	for(auto v:adj[u])if(v!=fa)re.pb(v);
	adj[u]=re;
	s[u]=c[u];
	for(auto v:adj[u]){
		dfs1(v,u);
		s[u]+=s[v],h[u]|=h[v];
	}
	h[u]|=s[u]>1&&a[u];
}

void dfs2(int u,int Sums,int Sumh){
	if(h[u]||Sumh||a[u])ans[u]=1;
	int m=SZ(adj[u]);
	vector<int>prs(m,0),sfs(m,0),prh(m,0),sfh(m,0);
	if(m){
		prs[0]=s[adj[u][0]];
		for(int i=1;i<m;i++)prs[i]=prs[i-1]+s[adj[u][i]];
		sfs[m-1]=s[adj[u][m-1]];
		for(int i=m-2;i>=0;i--)sfs[i]=sfs[i+1]+s[adj[u][i]];
		prh[0]=h[adj[u][0]];
		for(int i=1;i<m;i++)prh[i]=prh[i-1]|h[adj[u][i]];
		sfh[m-1]=h[adj[u][m-1]];
		for(int i=m-2;i>=0;i--)sfh[i]=sfh[i+1]|h[adj[u][i]];
	}
	Sums+=c[u];
	for(int i=0;i<m;i++){
		int v=adj[u][i],vs=Sums,vh=Sumh;
		if(i)vs+=prs[i-1],vh|=prh[i-1];
		if(i+1<m)vs+=sfs[i+1],vh|=sfh[i+1];
		if(vs>1&&a[u])vh=1;
		dfs2(v,vs,vh); 
	}
}

int main(){
	scanf("%d",&n);
	rep(i,1,n)a[i]=c[i]=read();
	rep(i,1,n-1){
		int u=read(),v=read();
		adj[u].pb(v),adj[v].pb(u);
		if(c[u]+c[v])a[u]=a[v]=1;
	}
	dfs1(1,0),dfs2(1,0,0);
	rep(i,1,n)print(ans[i]," \n"[i==n]);
	return 0;
}