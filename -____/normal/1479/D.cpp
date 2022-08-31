#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 333333;
const int Q = 22;
const int M = 1<<25;
int n,q,a[N],b[N],d[N],f[N][Q];
vector<int> v[N];
int tot,ls[M],rs[M],t[M],rt[N];
void modify(int&k,int kk,int x,int l=1,int r=n){
	if(!k)
		k=++tot;
	if(l==r){
		t[k]=t[kk]^b[x];
		return;
	}
	int h=l+r>>1;
	if(x<=h){
		modify(ls[k],ls[kk],x,l,h);
		rs[k]=rs[kk];
	}
	else{
		modify(rs[k],rs[kk],x,h+1,r);
		ls[k]=ls[kk];
	}
	t[k]=t[ls[k]]^t[rs[k]];
}
void dfs(int u,int fa){
	int i,x;
	d[u]=d[fa]+1;
	f[u][0]=fa;
	modify(rt[u],rt[fa],a[u]);
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
}
int lca(int x,int y){
	int j;
	if(d[x]<d[y])
		swap(x,y);
	for(j=20;j>=0;j--)
		if(d[f[x][j]]>=d[y])
			x=f[x][j];
	if(x==y)
		return x;
	for(j=20;j>=0;j--)
		if(f[x][j]!=f[y][j])
			x=f[x][j],y=f[y][j];
	return f[x][0];
}
int query(int k1,int k2,int L,int R,int l=1,int r=n){
	if(t[k1]==t[k2]||r<L||R<l||R<L)
		return -1;
	if(l==r)
		return l;
	int h=l+r>>1,o;
	o=query(ls[k1],ls[k2],L,R,l,h);
	if(o>0)
		return o;
	return query(rs[k1],rs[k2],L,R,h+1,r);
}
int main()
{
	srand(666);
	int i,j,x,y,z,l,r,o;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i=i+1)
		b[i]=(rand()<<15)^rand();
	dfs(1,0);
	for(j=1;j<=20;j++)
		for(i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	for(i=1;i<=q;i++){
		scanf("%d%d%d%d",&x,&y,&l,&r);
		z=a[lca(x,y)];
		if(l<=z&&z<=r){
			o=query(rt[x],rt[y],z,z);
			if(o<0)
				printf("%d\n",z);
			else{
				o=query(rt[x],rt[y],l,z-1);
				if(o>0)
					printf("%d\n",o);
				else{
					o=query(rt[x],rt[y],z+1,r);
					printf("%d\n",o);
				}
			}
		}
		else{
			o=query(rt[x],rt[y],l,r);
			printf("%d\n",o);
		}
	}
	return 0;
}