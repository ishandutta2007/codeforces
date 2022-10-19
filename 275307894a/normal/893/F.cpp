#include<cstdio>
#include<cstring>
#include<queue>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,tot,roots,dfn[100039],dh,top[100039],last,root[200039],a[100039],d[100039],ends[100039],now,cur;
queue<int> q;
struct tree{int l,r,f;}f[40000039];
struct yyy{int to,z;}tmp;
struct ljb{
	int head,h[100039];
	yyy f[200039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void dfs(int x,int last){
	dfn[++dh]=x;top[x]=dh;
	d[x]=d[last]+1;
	int cur=s.h[x];
	yyy tmp;
	while(cur!=-1){
		tmp=s.f[cur];
		if(tmp.to!=last)dfs(tmp.to,x);
		cur=tmp.z;
	}
	ends[x]=dh;
}
inline void xj(int &now){f[++tot]=f[now];now=tot;}
inline void get(int x,int y,int l,int r,int &now){
	xj(now);
	if(!f[now].f)f[now].f=y;
	else f[now].f=min(f[now].f,y);
	if(l==r) return;
	int m=l+r>>1;
	if(x<=m) get(x,y,l,m,f[now].l);
	else get(x,y,m+1,r,f[now].r);
}
inline int find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f[now].f;
	int m=(l+r)>>1,ans1=2e9,ans2=2e9;
	if(x<=m&&f[now].l) ans1=find(x,y,l,m,f[now].l);
	if(y>m&&f[now].r) ans2=find(x,y,m+1,r,f[now].r);
	return min(ans1,ans2);
}
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(int x){
	if(x>9) print(x/10);
	putchar(x%10+48);
}
int main(){
	memset(s.h,-1,sizeof(s.h));
//	freopen("1.in","r",stdin);
	register int i;
	read(n);read(roots);
	for(i=1;i<=n;i++) read(a[i]);
	for(i=1;i<n;i++) read(x),read(y),s.add(x,y),s.add(y,x);
	dfs(roots,0);
	q.push(roots);
	while(!q.empty()){
		now=q.front();q.pop();
		if(!root[d[now]]) root[d[now]]=root[d[now]-1];
		get(top[now],a[now],1,n,root[d[now]]);
		cur=s.h[now];
		while(cur!=-1){
			tmp=s.f[cur];
			if(d[tmp.to]>d[now]) q.push(tmp.to);
			cur=tmp.z;
		}
	}
	for(i=d[now]+1;i<=2*n;i++) root[i]=root[i-1];
	read(m);
	for(i=1;i<=m;i++){
		read(x);read(y);
		x=(x+last)%n+1;y=(y+last)%n;
		last=find(top[x],ends[x],1,n,root[d[x]+y]);
		print(last);putchar('\n');
	}
}