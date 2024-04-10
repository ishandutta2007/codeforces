#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
const int B = 19;

int n,Q;
int head[N],cnt;
int id[N];
int f1[N],f2[N],d[N],f[N][B],st[N],ed[N],dfx[N*2],totw,block;
int tong[2][N];
ll ans[N];
bool inq[N];

struct nd{
	int ne,to;
}e[N*2];
 
void in(int x,int y){
	e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;
}

struct qs{
	int id,m,l,r,b;
}q[N*2];
 
bool cmp(qs a,qs b){
	if(a.b!=b.b)return a.b<b.b;
	return a.r>b.r;
}
 
void dfs(int x,int fa){
	st[x]=++totw;
	dfx[totw]=x;
	for(int i=head[x];i;i=e[i].ne)
	if(e[i].to!=fa){
		int y=e[i].to;
		d[y]=d[x]+1;
		f[y][0]=x;
		dfs(y,x);
	}
	ed[x]=++totw;
	dfx[totw]=x;
}
 
int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	for(int i=B-1;i>=0;--i)
	if(d[f[x][i]]>=d[y]){
		x=f[x][i];
	}
	if(x==y)return x;
	for(int i=B-1;i>=0;--i)
	if(f[x][i]!=f[y][i]){
		x=f[x][i];
		y=f[y][i];
	}
	return f[x][0];
}
 
void prepare(){
	d[1]=1;dfs(1,-1);
	for(int i=1;i<B;++i)
	for(int t=1;t<=n;++t)
	f[t][i]=f[f[t][i-1]][i-1];
}

ll ret=0;

void insert(int x){
	inq[x]^=1;
	if(inq[x]){
		tong[id[x]][f1[x]]++;
		ret+=tong[id[x]^1][f1[x]];
	}
	else{
		tong[id[x]][f1[x]]--;
		ret-=tong[id[x]^1][f1[x]];
	}
}
 
 
int main(){
	scanf("%d",&n);
	block=sqrt(n)+1;
	for(int i=1;i<=n;++i)scanf("%d",id+i);
	for(int i=1;i<=n;++i)scanf("%d",f1+i),f2[i]=f1[i];
	sort(f2+1,f2+n+1);
	int nn=unique(f2+1,f2+n+1)-f2-1;
	for(int i=1;i<=n;++i)f1[i]=lower_bound(f2+1,f2+nn+1,f1[i])-f2;
	for(int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		in(x,y);
		in(y,x);
	}
	prepare();
	scanf("%d",&Q);
	for(int i=1,a,b;i<=Q;++i){
		scanf("%d%d",&a,&b);
		q[i].id=i;
		int p=lca(a,b);
		if(st[a]>st[b])swap(a,b);
		if(p==a)q[i].l=st[a],q[i].r=st[b],q[i].m=0;
		else	q[i].l=ed[a],q[i].r=st[b],q[i].m=p;
		q[i].b=q[i].l/block+1;
	}
	int L=1,R=0;
	sort(q+1,q+Q+1,cmp);
	for(int i=1;i<=Q;++i)
	{
		int l=q[i].l,r=q[i].r;
		while(L<l)insert(dfx[L]),L++;
		while(L>l)L--,insert(dfx[L]);
		while(R>r)insert(dfx[R]),R--;
		while(R<r)R++,insert(dfx[R]);
		if(q[i].m)insert(q[i].m);
		ans[q[i].id]=ret;
		if(q[i].m)insert(q[i].m);
	}
	for(int i=1;i<=Q;++i)printf("%I64d\n",ans[i]);
}