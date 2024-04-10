#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct T{
	int c[27],d[27],f,p;
	vector<int>e;
}t[N];
char s[N];
int d[N],q[N],id,dfn[N],L[N],R[N],ans[N*3],ed[N];
vector<int>v[N],u[N],w[N];
void add(int x){for(;x<=id;x+=x&-x)++d[x];}
int sum(int x){int r=0;for(;x;x-=x&-x)r+=d[x];return r;}
void ins(char*s,int g){
	int x=0,y;
	for(;*s;++s){
		y=*s-'a';
		if(!t[x].c[y])t[x].c[y]=++id,t[id].p=x;
		x=t[x].c[y];
	}
	t[x].e.push_back(g),ed[g]=x;
}
void pre(int x){
	int i,l,p;
	for(i=0,p=t[x].e.size();i<p;++i)L[t[x].e[i]]=id;
	for(i=0,l=v[x].size(),dfn[x]=++id;i<l;++i)pre(v[x][i]);
	for(i=0;i<p;++i)R[t[x].e[i]]=id;
}
int main(){
	int n,m,i,j,k,l=0,r=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%s",s),ins(s,i);
	for(i=0;i<26;++i)if(t[0].c[i])v[0].push_back(q[++r]=t[0].d[i]=t[0].c[i]);
	while(l!=r){
		i=q[++l],k=t[i].f;
		for(j=0;j<26;++j){
			if(t[i].c[j])v[t[k].d[j]].push_back(q[++r]=t[i].d[j]=t[i].c[j]),t[q[r]].f=t[k].d[j];
			else t[i].d[j]=t[k].d[j];
		}
	}
	id=0,pre(0);
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&j,&k,&l),--j;
		u[j].push_back(-l),w[j].push_back(i);
		u[k].push_back(l),w[k].push_back(i);
	}
	for(i=1;i<=n;++i){
		for(j=ed[i];j;j=t[j].p)add(dfn[j]);
		for(l=u[i].size(),j=0;j<l;++j){
			k=u[i][j];
			if(k<0)ans[w[i][j]]-=sum(R[-k])-sum(L[-k]);
			else ans[w[i][j]]+=sum(R[k])-sum(L[k]);
		}
	}
	for(i=1;i<=m;++i)printf("%d\n",ans[i]); 
	return 0;
}