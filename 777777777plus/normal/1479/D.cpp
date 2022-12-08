#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 3e5+5;
const int MXB = 19;
int head[N],cnt11,n,Q,id[N],d[N],f[N][MXB],st[N],ed[N],dfx[N*2],totw,block;
ll ans[N];
struct nd{int ne,to;}e[N*2];
struct questions{int id,m,l,r,b;int wl,wr;}q[N*2];
 
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
 
bool cmp(questions a,questions b)
{
	if(a.b!=b.b)return a.b<b.b;
	return a.r>b.r;
}
 
void in(int x,int y){e[++cnt11].to=y;e[cnt11].ne=head[x];head[x]=cnt11;}
 
void dfs(int x,int fa)
{
	st[x]=++totw;dfx[totw]=x;
	for(int i=head[x];i;i=e[i].ne)
	if(e[i].to!=fa)
	{
		int y=e[i].to;
		d[y]=d[x]+1;
		f[y][0]=x;
		dfs(y,x);
	}
	ed[x]=++totw;dfx[totw]=x;
}
 
int lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	for(int i=MXB-1;i>=0;--i)
	if(d[f[x][i]]>=d[y])x=f[x][i];
	if(x==y)return x;
	for(int i=MXB-1;i>=0;--i)
	if(f[x][i]!=f[y][i])
	x=f[x][i],y=f[y][i];
	return f[x][0];
}
 
void Pre()
{
	d[1]=1;dfs(1,-1);
	for(int i=1;i<MXB;++i)
	for(int t=1;t<=n;++t)
	f[t][i]=f[f[t][i-1]][i-1];
}
 
ll ret=0;
int l1[N],r1[N],ha[N];
bool cnt[N];
 
void insert(int x)
{
	x=id[x];
	cnt[x]^=1;
	int p=x/block+1;
	if(cnt[x])ha[p]++;
	else ha[p]--;
}
 
void output(int x){
	static int buf[N];
	while(x){
		buf[++buf[0]]=x%10;
		x/=10;
	}
	while(buf[0]){
		putchar(buf[buf[0]]+'0');
		--buf[0];
	}
	puts("");
}
 
int main()
{
	n=read();Q=read();
	block=800;
	for(int i=1;i<=n;++i)id[i]=read();
	for(int i=1,x,y;i<n;++i)x=read(),y=read(),in(x,y),in(y,x);
	Pre();
	for(int i=1,a,b,l,r;i<=Q;++i)
	{
		a=read();b=read();l=read();r=read();
		q[i].id=i;
		int p=lca(a,b);
		if(st[a]>st[b])swap(a,b);
		q[i].wl=l;q[i].wr=r;
		if(p==a)q[i].l=st[a],q[i].r=st[b],q[i].m=0;
		else	q[i].l=ed[a],q[i].r=st[b],q[i].m=p;
		q[i].b=q[i].l/block+1;
		ans[i]=-1;
	}
	int L=1,R=0;
	sort(q+1,q+Q+1,cmp);
	for(int i=1;i<=n;++i){
		int p=i/block+1;
		if(!l1[p])l1[p]=i;
		r1[p]=i;
	}
	for(int t=1;t<=Q;++t)
	{
		int l=q[t].l,r=q[t].r;
		while(L<l)insert(dfx[L]),L++;
		while(L>l)L--,insert(dfx[L]);
		while(R>r)insert(dfx[R]),R--;
		while(R<r)R++,insert(dfx[R]);
		if(q[t].m)insert(q[t].m);
		int wl=q[t].wl,wr=q[t].wr;
		int bl=wl/block+1;
		int br=wr/block+1;
		if(bl==br){
			for(int i=wl;i<=wr;++i){
				if(cnt[i]){
					ans[q[t].id]=i;
					break;
				}
			}
		}
		else{
			bool flag=0;
			for(int i=wl;i/block+1==bl;++i){
				if(cnt[i]){
					ans[q[t].id]=i;
					flag=1;
					break;
				}	
			}
			if(!flag){
				for(int i=wr;i/block+1==br;--i){
					if(cnt[i]){
						ans[q[t].id]=i;
						flag=1;
						break;
					}
				}
			}
			if(!flag){
				for(int i=bl+1;i<=br-1;++i){
					if(ha[i]){
						for(int j=l1[i];j<=r1[i];++j){
							if(cnt[j]){
								ans[q[t].id]=j;
								flag=1;
								break;
							}
						}
						break;
					}
				}
			}
		}
		if(q[t].m)insert(q[t].m);
	}
	for(int i=1;i<=Q;++i)
	if(ans[i]==-1)puts("-1");
	else output(ans[i]);
}