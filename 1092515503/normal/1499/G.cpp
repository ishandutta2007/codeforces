#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n1,n2,n,m,q,dsu[400100],to[400100],sum[400100][2],bit[400100],res;//0:blue 1:red
bool rev[400100];
int find(int x){
	if(dsu[x]==x)return x;
	if(dsu[dsu[x]]==dsu[x])return dsu[x];
	int ret=find(dsu[x]);
	rev[x]^=rev[dsu[x]];
	return dsu[x]=ret;
}
bool reversed(int x){
	if(dsu[x]==x)return rev[x];
	int X=find(x);
	return rev[x]^rev[X];
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	(res+=mod-sum[x][rev[x]])%=mod,(res+=mod-sum[y][rev[y]])%=mod;
	rev[x]^=rev[y],dsu[x]=y,(sum[y][0]+=sum[x][rev[x]])%=mod,(sum[y][1]+=sum[x][!rev[x]])%=mod;
	(res+=sum[y][rev[y]])%=mod;
}
void REV(int x){
	x=find(x);
	(res+=mod-sum[x][rev[x]])%=mod;
	rev[x]^=1;
	(res+=sum[x][rev[x]])%=mod;
}
void link(int x,int y,int id){
	sum[id][1]=bit[id]=(bit[id-1]<<1)%mod,dsu[id]=id;
	if(!to[x]&&!to[y]){REV(id),to[x]=to[y]=id;return;}
	if(!to[x])swap(x,y);
	if(!to[y]){
		if(!reversed(to[x]))REV(id);
		merge(to[x],id);
		to[x]=0,to[y]=id;
		return;
	}
	if(reversed(to[x])!=reversed(to[y]))REV(to[x]);
	if(!reversed(to[x]))REV(id);
	merge(to[x],id),merge(to[y],id);
	to[x]=to[y]=0;
}
int main(){
	scanf("%d%d%d",&n1,&n2,&m),n=n1+n2,bit[0]=1;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),link(x,y+n1,i);
	scanf("%d",&q);
	for(int i=1,tp,x,y;i<=q;i++){
		scanf("%d",&tp);
		if(tp==1)scanf("%d%d",&x,&y),link(x,y+n1,++m),printf("%d\n",res);
		else{
			int cnt=0;
			for(int j=1;j<=m;j++)cnt+=reversed(j);
			printf("%d ",cnt);
			for(int j=1;j<=m;j++)if(reversed(j))printf("%d ",j);puts("");
		}
		fflush(stdout);
	}
	return 0;
}
/*
3 2 4
1 2
1 1
3 2
2 2
2
1 2 1
2
*/