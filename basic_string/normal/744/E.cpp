#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3,M=3e6+3,P1=1e9-9,P2=1e9-7,B=133;
int p1[N],p2[N],id[33][N];
basic_string<int>g[M];
bool v[N],b[N],f;
struct S{
	char s[N];
	int n,h1[N],h2[N];
	pair<int,int>get(int l,int r){return make_pair((h1[r]+(P1-h1[l-1])*1ll*p1[r-l+1])%P1,(h2[r]+(P2-h2[l-1])*1ll*p2[r-l+1])%P2);}
	void in(){
		int i;
		scanf("%s",s+1),n=strlen(s+1);
		for(i=1;i<=n;++i)h1[i]=(h1[i-1]*1ll*B+s[i])%P1,h2[i]=(h2[i-1]*1ll*B+s[i])%P2;
	}
}s[33];
void dfs(int x){
	v[x]=1;
	for(int i:g[x])if(v[i]){
		if(!b[i]){f=1;return;}
	}else dfs(i);
	b[x]=1;
}
void add(int x,int y,int u,int v){g[id[x][y]]+=id[u][v];}
bool wk(int l,int r){
	int i,j,k,u,v,o;
	memset(::v,0,sizeof ::v),memset(b,0,sizeof b),f=0;
	for(g[1]={},i=l;i<=r;++i)for(j=1;j<=s[i].n;++j)g[id[i][j]]={};
	for(i=l;i<=r;++i)for(add(0,0,i,1),j=1;j<=s[i].n;++j)for(k=l;k<=r;++k){
		u=s[i].n-j+1,v=s[k].n,o=min(u,v);
		if(s[i].get(j,j+o-1)==make_pair(s[k].h1[o],s[k].h2[o])){
			if(u<v)add(i,j,k,u+1);
			else if(u>v)add(i,j,i,j+v);
			else if(j>1)add(i,j,0,0);
		}
	}
	for(dfs(1),i=l;i<=r;++i)for(j=1;j<=s[i].n;++j)if(dfs(id[i][j]),f)return 0;
	return 1;
}
int main(){
	int n,i,j,ct=1,ans=0;
	scanf("%d",&n),p1[0]=p2[0]=1,id[0][0]=1;
	for(i=1;i<N;++i)p1[i]=p1[i-1]*1ll*B%P1,p2[i]=p2[i-1]*1ll*B%P2;
	for(i=1;i<=n;++i)for(s[i].in(),j=1;j<=s[i].n;++j)id[i][j]=++ct;
	for(i=j=1;i<=n;++i){
		j=max(j,i);
		while(j<=n&&wk(i,j))++j;
		ans+=j-i;
	}
	printf("%d",ans);
	return 0;
}