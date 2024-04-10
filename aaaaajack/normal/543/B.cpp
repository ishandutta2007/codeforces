#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 3010
#define M 3010
#define inf 0x3f3f3f3f
using namespace std;
int dis[N][N],in[N],q[N],qt,qf;
int to[M*2],nxt[M*2],head[N];
int main(){
	int n,m,i,j,a,b,s[2],t[2],l[2],ans=-1;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		to[i*2+1]=b;
		to[i*2+2]=a;
		nxt[i*2+1]=head[a];
		nxt[i*2+2]=head[b];
		head[a]=i*2+1;
		head[b]=i*2+2;
	}
	memset(dis,0x3f,sizeof(dis));
	for(i=1;i<=n;i++){
		dis[i][i]=0;
		qf=0;
		qt=1;
		q[qf]=i;
		while(qf<qt){
			a=q[qf++];
			for(j=head[a];j;j=nxt[j]){
				if(dis[i][a]+1<dis[i][to[j]]){
					dis[i][to[j]]=dis[i][a]+1;
					q[qt++]=to[j];
				}
			}
		}
	}
	scanf("%d%d%d",&s[0],&t[0],&l[0]);
	scanf("%d%d%d",&s[1],&t[1],&l[1]);
	for(i=1;i<=n;i++){
		if(dis[i][s[0]]==inf||dis[i][s[1]]==inf) continue;
		for(j=1;j<=n;j++){
			if(dis[i][j]==inf||dis[j][t[0]]==inf||dis[j][t[1]]==inf) continue;
			if(dis[i][s[0]]+dis[i][j]+dis[j][t[0]]>l[0]) continue;
			if(dis[i][s[1]]+dis[i][j]+dis[j][t[1]]>l[1]) continue;
			ans=max(ans,m-dis[i][s[0]]-dis[i][s[1]]-dis[i][j]-dis[j][t[0]]-dis[j][t[1]]);
		}
	}
	for(i=1;i<=n;i++){
		if(dis[i][s[0]]==inf||dis[i][t[1]]==inf) continue;
		for(j=1;j<=n;j++){
			if(dis[i][j]==inf||dis[j][t[0]]==inf||dis[j][s[1]]==inf) continue;
			if(dis[i][s[0]]+dis[i][j]+dis[j][t[0]]>l[0]) continue;
			if(dis[i][t[1]]+dis[i][j]+dis[j][s[1]]>l[1]) continue;
			ans=max(ans,m-dis[i][t[1]]-dis[i][s[0]]-dis[i][j]-dis[j][t[0]]-dis[j][s[1]]);
		}
	}
	if(dis[s[0]][t[0]]<=l[0]&&dis[s[1]][t[1]]<=l[1]){
		ans=max(ans,m-dis[s[0]][t[0]]-dis[s[1]][t[1]]);
	}
	printf("%d\n",ans);
	return 0;
}