#include<bits/stdc++.h>
using namespace std;

const int maxn=200111;
vector<int>g[maxn];
int n,m,p[maxn],k,d[maxn],q[maxn],t1[maxn],t2[maxn];

void bfs(int s){
	int fr=0,rr=0;
	q[rr++]=s;
	memset(d,-1,sizeof(d));
	d[s]=0;
	for(;fr<rr;fr++){
		int x=q[fr];
		for(int i=0;i<(int)g[x].size();i++){
			if(d[g[x][i]]==-1){
				d[g[x][i]]=d[x]+1;
				q[rr++]=g[x][i];
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[v].push_back(u);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)scanf("%d",p+i);
	int s=p[1],t=p[k];
	bfs(t);
	for(int x=1;x<=n;x++)for(int i=0;i<(int)g[x].size();i++){
		if(d[g[x][i]]==d[x]+1){
			if(!t1[g[x][i]])t1[g[x][i]]=x;
			else t2[g[x][i]]=x;
		}
	}
	int ans1=0,ans2=0;
	for(int i=1;i<k;i++){
		if(d[p[i+1]]!=d[p[i]]-1)ans1++;
		if(p[i+1]!=t1[p[i]]||t2[p[i]])ans2++;
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}