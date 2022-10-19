#include<cstdio>
#include<cmath>
#include<map>
#include<vector>
#define N 100039
#define I inline
using namespace std;
int n,m,k,q,x[N],y[N],z[N],st[N],en[N],fa[N],now,un,wn,fl[N],ans[N];
map<int,int> flag[N],f[N];vector<int>c[N],g[N];
I int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
I void make(int x){
	register int i,j,now1,now2;
	for(i=0;i<g[x].size();i++){
		for(j=i+1;j<g[x].size();j++) now1=g[x][i],now2=g[x][j],flag[now1].count(now2)&&(f[now1][now2]++),flag[now2].count(now1)&&(f[now2][now1]++);
	} g[x].clear();
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;scanf("%d%d",&n,&m);k=sqrt(m/log2(log2(m)));for(i=1;i<=n;i++) fa[i]=i;
	for(i=1;i<=m;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]),c[z[i]].push_back(i);
	scanf("%d",&q);for(i=1;i<=q;i++) scanf("%d%d",&st[i],&en[i]),flag[st[i]][en[i]]=1;;
	for(i=1;i<=m;i++){
		if(c[i].size()<=k){
			for(j=0;j<c[i].size();j++){
				now=c[i][j];un=find(x[now]);wn=find(y[now]);
				if(un==wn) continue;fa[un]=wn;
			}
			for(j=0;j<c[i].size();j++) now=c[i][j],!fl[x[now]]&&(g[find(x[now])].push_back(x[now]),fl[x[now]]=1),!fl[y[now]]&&(g[find(y[now])].push_back(y[now]),fl[y[now]]=1);
			for(j=0;j<c[i].size();j++)now=c[i][j],make(find(x[now]));
			for(j=0;j<c[i].size();j++) now=c[i][j],fa[x[now]]=x[now],fa[y[now]]=y[now],fl[x[now]]=0,fl[y[now]]=0;
		}
		else{
			for(j=0;j<c[i].size();j++){
				now=c[i][j];un=find(x[now]);wn=find(y[now]);
				if(un==wn) continue;fa[un]=wn;//printf("%d %d\n",un,wn);
			}
			for(j=1;j<=q;j++) ans[j]+=(find(st[j])==find(en[j]));
			for(j=1;j<=n;j++) fa[j]=j;//printf("\n");
		}
	}
	for(i=1;i<=q;i++)printf("%d\n",ans[i]+f[st[i]][en[i]]);
}