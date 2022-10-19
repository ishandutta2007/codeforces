#include<bits/stdc++.h>
using namespace std;
int n,m,head[100100],cnt,X,Y;
struct node{int to,next,val;}edge[200100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
template<int&RT>struct RTT{
private:
	int len[100100],son[100100],anc[17][100100],top[100100],val[100100],dis[100100];
	int ord[100100],sum[100100],rnk[100100],mn[17][100100],tot;
	void dfsdat(int x){
		for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=anc[0][x]){
			anc[0][y]=x,dis[y]=dis[x]+edge[i].val,val[y]=edge[i].val;
			dfsdat(y);
			if(len[x]<len[y])len[x]=len[y],son[x]=y;
		}
		len[x]+=val[x];
	}
	void dfspar(int x){
		if(!top[x])top[x]=x,ord[++tot]=x;
		if(son[x])top[son[x]]=top[x];
		for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=anc[0][x])
			dfspar(y);
	}
	pair<int,int>p[100100];
public:
	void Init(){
		dfsdat(RT),dfspar(RT);
//		printf("%d:\n",RT);
//		for(int i=1;i<=n;i++)printf("%d ",len[i]);puts("");
//		for(int i=1;i<=n;i++)printf("%d ",top[i]);puts("");
//		for(int i=1;i<=n;i++)printf("%d ",dis[i]);puts("");
		for(int i=1;i<=tot;i++)p[i]=make_pair(-len[ord[i]],ord[i]);
		sort(p+1,p+tot+1);
		for(int i=1;i<=tot;i++)ord[i]=p[i].second;
//		for(int i=1;i<=tot;i++)printf("%d ",ord[i]);puts("");
		for(int i=1;i<=tot;i++)rnk[ord[i]]=i,sum[i]=sum[i-1]+len[ord[i]];
		for(int x=1;x<=n;x++)mn[0][x]=rnk[top[anc[0][x]]];
		for(int i=1;i<=16;i++)for(int x=1;x<=n;x++)
			anc[i][x]=anc[i-1][anc[i-1][x]],
			mn[i][x]=min(mn[i-1][x],mn[i-1][anc[i-1][x]]);
	}
	int query(int x,int y){
		y<<=1;
		if(rnk[top[x]]<y)return sum[min(y-1,tot)];
		int num=len[x];
		for(int i=16;i>=0;i--)if(anc[i][x]&&mn[i][x]>=y)
			num+=dis[anc[0][x]]-dis[anc[0][anc[i][x]]],x=anc[i][x];
		x=anc[0][x];
//		printf("%d %d\n",x,num);
		return max(sum[y-2]+num,sum[y-1]-len[son[x]]+num);
	}
};
int dis[100100];
void dfsdia(int x,int fa){
	for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa)
		dis[y]=dis[x]+edge[i].val,dfsdia(y,x);
}
RTT<X>a;
RTT<Y>b;
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
	dis[1]=0,dfsdia(1,0);for(int i=1;i<=n;i++)if(dis[X]<=dis[i])X=i;
	dis[X]=0,dfsdia(X,0);for(int i=1;i<=n;i++)if(dis[Y]<=dis[i])Y=i;
	a.Init(),b.Init();
	for(int i=1,las=0,x,y;i<=m;i++){
		scanf("%d%d",&x,&y),x=(x+las-1)%n+1,y=(y+las-1)%n+1;
		printf("%d\n",las=max(a.query(x,y),b.query(x,y)));
	}
	return 0;
}
/*
9 1
2 1 903
1 8 76
5 6 737
3 4 204
8 7 676
6 1 694
3 1 65
2 9 27
4 1
*/