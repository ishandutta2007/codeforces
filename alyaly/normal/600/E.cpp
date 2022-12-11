#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define mid (l+r)/2
#define int long long
#define N 100000
using namespace std;
int n,dq[N+1],a[N+1],b[4*N+1],nxt[4*N+1],ls[N+1],p,q,pb;
int fa[N+1],fc[N+1],ns[N+1],lc[N+1],sz[N+1],rt[N+1];
int seg[50*N+1],bh[50*N+1],son[50*N+1][2],ans[N+1];
queue<int>qu;
int lb(int np,int nq){ls[np]=(a[np]?nxt[ls[np]]:a[np])=++pb,b[pb]=nq;}
void putin(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>dq[i],sz[i]=1;
	for(int i=1;i<n;i++)cin>>p>>q,lb(p,q),lb(q,p);
}
void tttree(int x){
	for(int i=a[x];i;i=nxt[i]){
		if(fa[x]!=b[i]){
			fa[b[i]]=x,lc[x]=(fc[x]?ns[lc[x]]:fc[x])=b[i];
			tttree(b[i]);
		}
	}
}
void segup(int u,int l,int r){
	if(l!=r){
		if(seg[son[u][0]]>seg[son[u][1]])bh[u]=bh[son[u][0]];
		else if(seg[son[u][0]]==seg[son[u][1]])bh[u]=bh[son[u][0]]+bh[son[u][1]];
		else bh[u]=bh[son[u][1]];
		seg[u]=max(seg[son[u][0]],seg[son[u][1]]);
	}else bh[u]=l;
}
void segadd(int u,int l,int r,int np,int nx){
	if(l==r)seg[u]+=nx,bh[u]=l;
	else{
		if(np<=mid)segadd((son[u][0]?son[u][0]:(qu.pop(),son[u][0]=qu.front())),l,mid,np,nx);
		else segadd((son[u][1]?son[u][1]:(qu.pop(),son[u][1]=qu.front())),mid+1,r,np,nx);
		segup(u,l,r);
	}
}
void segmge(int u,int nu,int l,int r){
	if(l==r)seg[u]+=seg[nu],bh[u]=bh[nu];
	else{
		if(son[nu][0])segmge((son[u][0]?son[u][0]:(qu.pop(),son[u][0]=qu.front())),son[nu][0],l,mid);
		if(son[nu][1])segmge((son[u][1]?son[u][1]:(qu.pop(),son[u][1]=qu.front())),son[nu][1],mid+1,r);
		segup(u,l,r);
	}
}
void segclr(int u,int l,int r){
	if(!u)return;
	if(l!=r)segclr(son[u][0],l,mid),segclr(son[u][1],mid+1,r);
	son[u][0]=son[u][1]=seg[u]=bh[u]=0,qu.push(u);
}
void dfs(int x){
	for(int i=fc[x];i;i=ns[i]){
		dfs(i);
		if(sz[rt[x]]>sz[rt[i]])segmge(rt[x],rt[i],1,n),segclr(rt[i],1,n),sz[rt[x]]+=sz[rt[i]];
		else segmge(rt[i],rt[x],1,n),segclr(rt[x],1,n),sz[rt[i]]+=sz[rt[x]],rt[x]=rt[i];
	}
	ans[x]=bh[rt[x]];
}
signed main(){
//	freopen("late.in","r",stdin);
//	freopen("late.out","w",stdout);
	putin(),tttree(1),pb=n;
	for(int i=pb+1;i<=50*N;i++)qu.push(i);
	for(int i=1;i<=n;i++)rt[i]=i,segadd(i,1,n,dq[i],1);
	dfs(1);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);printf("\n");
	return 0;
}
/*
9
3 2 3 1 2 1 1 3 1
2 1
1 3
2 4
2 5
2 6
3 7
7 8
7 9
*/