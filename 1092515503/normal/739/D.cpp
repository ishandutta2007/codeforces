#include<bits/stdc++.h>
using namespace std;
int n,h[510],l[510],num[510],H[510],id[510][510],tot,fa[510];
char s[20],t[20];
namespace MaxFlow{
	const int N=2010,M=2000000;
	int head[N],cur[N],dep[N],cnt,S,T,res;
	struct node{int to,next,val;}edge[M];
	void ae(int u,int v,int w){
//		printf("%d %d %d\n",u,v,w);
		edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
		edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
	}
	queue<int>q;
	inline bool bfs(){
		memset(dep,0,sizeof(dep)),q.push(S),dep[S]=1;
		while(!q.empty()){
			register int x=q.front();q.pop();
			for(register int i=cur[x]=head[x];i!=-1;i=edge[i].next)
				if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
		}
		return dep[T]>0;
	}
	bool reach;
	inline int dfs(int x,int flow){
		if(x==T){res+=flow,reach=true;return flow;}
		int used=0;
		for(register int &i=cur[x];i!=-1;i=edge[i].next){
			if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
			register int ff=dfs(edge[i].to,min(edge[i].val,flow-used));
			if(ff){edge[i].val-=ff,edge[i^1].val+=ff,used+=ff;if(used==flow)break;}
		}
		return used;
	}
	inline void Dinic(){while(bfs()){reach=true;while(reach)reach=false,dfs(S,0x3f3f3f3f);}}
}using namespace MaxFlow;
vector<int>v[510];
int main(){
	scanf("%d",&n),memset(H,-1,sizeof(H));
	for(int i=1;i<=n;i++){
		scanf("%s%s",s,t);
		if(s[0]=='?')h[i]=-1;else sscanf(s,"%d",&h[i]);
		if(t[0]=='?')l[i]=-1;else sscanf(t,"%d",&l[i]);
	}
	for(int i=1;i<=n;i++)if(l[i]!=-1)num[l[i]]=l[i],H[l[i]]=0;
	for(int i=1;i<=n;i++)if(h[i]==0&&l[i]!=-1)(num[l[i]]+=l[i]-1)%=l[i];
//	for(int i=1;i<=n;i++)printf("%d %d\n",h[i],l[i]);
	int p=-1;
	for(int j=1;j<=n;j++)if(l[j]!=-1)p=l[j];
	if(p==-1)for(int i=1;i<=n;i++)if(h[i]==0&&l[i]==-1){h[i]=0,l[i]=p=1;break;}
	if(p==-1)for(int i=1;i<=n;i++)if(h[i]==-1&&l[i]==-1){h[i]=0,l[i]=p=1;break;}
	if(p==-1){puts("-1");return 0;}
	int sum=0;
	for(int i=1;i<=n;i++)if(h[i]!=-1&&l[i]!=-1)H[l[i]]=max(H[l[i]],h[i]);
	for(int i=1;i<=n;i++)if(H[i]!=-1)sum+=H[i];
	if(sum>n){puts("-1");return 0;}
	int nH=-1;
	for(int i=1;i<=n;i++)if(h[i]!=-1&&l[i]==-1)nH=max(nH,h[i]); 
//	for(int i=1;i<=n;i++)printf("%d ",H[i]);puts("");
/*	for(int i=1;i<=n;i++){
		if(H[i]==-1)continue;
		for(int j=1;j<=n;j++)if(l[j]==i)printf("<%d,%d>",h[j],l[j]);
		puts("");
	}*/
//	for(int i=1;i<=n;i++)if(l[i]==-1)printf("[%d,%d]",h[i],l[i]);
//	for(int i=1;i<=n;i++)if(num[i])printf("<%d:%d>",i,num[i]);puts("");
//	printf("QWQ:%d\n",nH);
	for(int i=1;i<=n;i++){
		if(H[i]==-1&&nH!=-1)continue;
//		printf("%d:\n",i);
		int all=0;
		memset(head,-1,sizeof(head)),cnt=0,S=n+1,T=n+2,tot=n+2,res=0;
		for(int j=1;j<=n;j++)for(int k=0;k<=(j==i?max(nH,H[j]):H[j]);k++)
			all+=(k==0?num[j]:1),ae(id[j][k]=++tot,T,k==0?num[j]:1);
		for(int j=1;j<=n;j++){
			ae(S,j,1);
			if(h[j]==-1&&l[j]==-1)for(int k=n+3;k<=tot;k++)ae(j,k,1);
			else if(h[j]!=-1){
				if(l[j]!=-1&&h[j])ae(j,id[l[j]][h[j]],1);
				if(l[j]==-1)for(int k=0;k<=n;k++)if(k==i||H[k]>=h[j])ae(j,id[k][h[j]],1);
			}else for(int k=0;k<=(l[j]==i?max(nH,H[l[j]]):H[l[j]]);k++)ae(j,id[l[j]][k],1);
		}
		Dinic();
/*		for(int j=1;j<=n;j++)if(H[j]!=-1){
			for(int k=0;k<=(j==i?max(nH,H[j]):H[j]);k++)
				for(int e=head[id[j][k]];e!=-1;e=edge[e].next)
					if(edge[e].to<=n&&edge[e].val)printf("{%d,%d:%d}",j,k,edge[e].to);
			puts("");
		}
		printf("QWQ:%d,%d\n",all,res);*/
		if(res!=all)continue;
		H[i]=max(H[i],nH);
		for(int j=1;j<=n;j++)for(int k=0;k<=H[j];k++)
			for(int e=head[id[j][k]];e!=-1;e=edge[e].next)
				if(edge[e].to<=n&&edge[e].val)l[edge[e].to]=j,h[edge[e].to]=k;
		for(int j=1;j<=n;j++)if(h[j]==0&&l[j]==-1)l[j]=1;
		for(int j=1;j<=n;j++)if(h[j]!=-1&&l[j]==-1)l[j]=i;
		for(int j=1;j<=n;j++)if(h[j]==-1&&l[j]==-1)h[j]=0,l[j]=1;
		for(int j=1;j<=n;j++){if(h[j]==-1)h[j]=1;if(l[j]==-1)l[j]=p;}
		for(int j=1;j<=n;j++)assert(h[j]!=-1),assert(l[j]!=-1);
		/*for(int j=1;j<=n;j++){
			if(H[j]==-1)continue;
			for(int k=1;k<=n;k++)if(l[k]==j)printf("<%d:%d,%d>",k,h[k],l[k]);
			puts("");
		}*/
		for(int j=1;j<=n;j++)id[l[j]][h[j]]=j;
		for(int j=1;j<=n;j++)if(h[j])fa[j]=id[l[j]][h[j]-1];else{
			v[l[j]].push_back(j);
			if(v[l[j]].size()!=l[j])continue;
			for(int k=0;k<l[j];k++)fa[v[l[j]][k]]=v[l[j]][(k+1)%l[j]];v[l[j]].clear();
		}
//		for(int j=1;j<=n;j++)printf("%d ",v[j].size());puts("");
		for(int j=1;j<=n;j++)printf("%d ",fa[j]);puts("");
		return 0;
//		for(int j=1;j<=n;j++)printf("%d %d\n",h[j],l[j]);
	}
	puts("-1");
	return 0;
}