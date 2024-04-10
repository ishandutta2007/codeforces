#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,head[300100],col[300100],cnt,cc[300100],da[300100],db[300100],a[300100],b[300100],res;
struct node{
	int to,next,val;
}edge[600100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
void findpath(int x,int fa){
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(edge[i].to==fa)continue;
		findpath(edge[i].to,x);
		if(col[edge[i].to]==-1)col[x]=-1;
	}
}
void dye(int x,int ccc){
	for(int i=head[x];i!=-1;i=edge[i].next)if(col[edge[i].to]==0)col[edge[i].to]=ccc,cc[ccc]++,dye(edge[i].to,ccc);
}
void finda(int x,int fa){
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)da[edge[i].to]=da[x]+edge[i].val,finda(edge[i].to,x);
}
void findb(int x,int fa){
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)db[edge[i].to]=db[x]+edge[i].val,findb(edge[i].to,x);
}
struct kk{
	int id,f,g;
	kk(int x=0,int y=0,int z=0){id=x,f=y,g=z;}
	friend bool operator <(const kk &x,const kk &y){
		return da[x.id]<da[y.id];
	}
};
vector<kk>v;
signed main(){
	scanf("%I64d%I64d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<n;i++)scanf("%I64d%I64d%I64d",&x,&y,&z),ae(x,y,z);
	col[n]=-1;
	findpath(1,0);
	finda(1,0);
	findb(n,0);
	for(int i=1;i<=n;i++)if(col[i]==-1)dye(i,i);
//	for(int i=1;i<=n;i++)printf("%I64d ",col[i]);
	for(int i=1,x;i<=n;i++){
		if(cc[i]<=1)continue;
		while(m--)scanf("%I64d",&x),printf("%I64d\n",da[n]);
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(col[i]==-1)a[i]=max(a[i],da[i]),b[i]=max(b[i],db[i]);
		else a[col[i]]=max(a[col[i]],da[i]),b[col[i]]=max(b[col[i]],db[i]);
	}
	for(int i=1;i<=n;i++)if(col[i]==-1)v.push_back(kk(i,a[i],b[i]));
	sort(v.begin(),v.end());
//	for(int i=0;i<v.size();i++)printf("(%lld,%lld,%lld)\n",v[i].id,v[i].f,v[i].g);
	for(int i=v.size()-1;i>=0;i--){
		if(i+1<v.size())v[i].g=max(v[i].g,v[i+1].g);
		if(i+2<v.size())res=max(res,v[i].f+v[i+2].g);
		if(i+1<v.size()&&(cc[v[i].id]||cc[v[i+1].id]))res=max(res,v[i].f+v[i+1].g);
	}
	for(int i=1,x;i<=m;i++){
		scanf("%I64d",&x);
		printf("%I64d\n",min(x+res,da[n]));
	}
	return 0;
}