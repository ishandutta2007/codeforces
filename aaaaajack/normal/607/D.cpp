#include<cstdio>
#include<vector>
#define N 200100
#define Q 1000000007
using namespace std;
vector<int> g[N];
int in[N],out[N],deg[N],now;
int tp[N],p[N],par[N];
int mul[N<<2],sum[N<<2],v[N];
void DFS(int u){
	in[u]=now++;
	for(int i=0;i<g[u].size();i++){
		DFS(g[u][i]);
	}
	out[u]=now;
}
void push(int u){
	mul[u<<1]=1LL*mul[u<<1]*mul[u]%Q;
	mul[u<<1|1]=1LL*mul[u<<1|1]*mul[u]%Q;
	mul[u]=1;
}
int qsum(int u){
	return 1LL*mul[u]*sum[u]%Q;
}
void pull(int u){
	sum[u]=(qsum(u<<1)+qsum(u<<1|1))%Q;
}
void set(int u,int l,int r,int x,int val){
	if(l+1==r){
		sum[u]=val;
		return;
	}
	push(u);
	if(x<(l+r)/2) set(u<<1,l,(l+r)/2,x,val);
	else set(u<<1|1,(l+r)/2,r,x,val);
	pull(u);
}
int seg_op(int u,int l,int r,int ql,int qr,int x){
	if(l==ql&&r==qr){
		mul[u]=1LL*mul[u]*x%Q;
		return qsum(u);
	}
	int m=(l+r)/2,res;
	push(u);
	if(qr<=m) res=seg_op(u<<1,l,m,ql,qr,x);
	else if(ql>=m) res=seg_op(u<<1|1,m,r,ql,qr,x);
	else{
		res=seg_op(u<<1,l,m,ql,m,x);
		res+=seg_op(u<<1|1,m,r,m,qr,x);
		res%=Q;
	}
	pull(u);
	return res;
}
int inv(int x){
	int r=1,y=Q-2;
	while(y){
		if(y&1) r=1LL*r*x%Q;
		x=1LL*x*x%Q;
		y>>=1;
	}
	return r;
}
int main(){
	int n=1,q,u=1;
	scanf("%d%d",&v[1],&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&tp[i],&p[i]);
		if(tp[i]==1){
			scanf("%d",&v[++n]);
			g[p[i]].push_back(n);
			par[n]=p[i];
		}
	}
	for(int i=1;i<=n;i++) deg[i]=1;
	DFS(1);
	for(int i=0;i<n*4;i++) mul[i]=1;
	set(1,0,n,in[1],v[1]);
	for(int i=0;i<q;i++){
		if(tp[i]==1){
			++u;
			set(1,0,n,in[u],v[u]);
			deg[p[i]]++;
			seg_op(1,0,n,in[p[i]],out[p[i]],1LL*deg[p[i]]*inv(deg[p[i]]-1)%Q);
		}
		else{
			int g=par[p[i]];
			int sum=seg_op(1,0,n,in[p[i]],out[p[i]],1),div=g?1LL*v[g]*inv(seg_op(1,0,n,in[g],in[g]+1,1))%Q:1;
			printf("%d\n",1LL*sum*div%Q);
		}
	}
	return 0;
}