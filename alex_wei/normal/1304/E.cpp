#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>

char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
#define putchar(x) (*O++=x)
#define flush() fwrite(obuf,O-obuf,1,stdout)
inline int read(){
	int x=0,sign=0; char s=getchar();
	while(!isdigit(s))sign|=s=='-',s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
	return sign?-x:x;
}
void print(int x){
    if(x>9)print(x/10);
    putchar(x%10+'0');
}

const int N=1e5+5;
int n,q,dep[N],fa[N][20];
vector <int> e[N];
void dfs(int id,int f,int d){
	dep[id]=d,fa[id][0]=f;
	for(auto to:e[id])if(to!=f)dfs(to,id,d+1);
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=18;i>=0;i--)if(dep[fa[u][i]]>=dep[v])u=fa[u][i];
	if(u==v)return u;
	for(int i=18;i>=0;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
int dis(int u,int v){
	int d=LCA(u,v);
	return dep[u]+dep[v]-dep[d]*2;
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0,0);
	for(int j=1;j<20;j++)for(int i=1;i<=n;i++)fa[i][j]=fa[fa[i][j-1]][j-1];
	cin>>q;
	while(q--){
		int x,y,a,b,k;
		cin>>x>>y>>a>>b>>k;
		int dp=LCA(x,y),dn=LCA(a,b),ln=dis(a,b);
		if(ln%2==k%2&&ln<=k){
			puts("YES");
			continue;
		}
		int circ=dis(a,y)+dis(x,b)+1;
		int circ2=dis(a,x)+dis(y,b)+1;
		if(circ%2==k%2&&circ<=k)puts("YES");
		else if(circ2%2==k%2&&circ2<=k)puts("YES");
		else{
			int c=dis(x,y)+1;
			if(c%2&&circ+c<=k||c%2&&circ2+c<=k)puts("YES");
			else puts("NO");
		}
	}
    return 0;
}
/*
5
1 2
2 3
3 4
4 5
1
1 5 2 3 4
*/