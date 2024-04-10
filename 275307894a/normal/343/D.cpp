#include<cstdio>
#include<cstring>
using namespace std;
int d[500039],idea,siz[500039],top[500039],son[500039],id[500039],fa[500039],x,y,z,n,m,k,f[2000039],sum[2000039];
struct yyy{int to,z;};
struct ljb{
	int head,h[500039];
	yyy f[1000039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void push(int now){
	f[now<<1]=f[now<<1|1]=f[now];
	f[now]=0;
}
inline void get(int x,int y,int z,int l,int r,int now){
	if(x<=l&&r<=y) {f[now]=z;return;}
	if(f[now]) push(now);
	int m=(l+r)>>1;
	if(x<=m) get(x,y,z,l,m,now<<1);
	if(y>m) get(x,y,z,m+1,r,now<<1|1);
	return;
}
inline int find(int x,int l,int r,int now){
	if(l==r) return (f[now]+1)/2;
	if(f[now]) push(now);
	int m=(l+r)>>1;
	if(x<=m) return find(x,l,m,now<<1);
	else return find(x,m+1,r,now<<1|1);
}
inline void dfs1(int x,int last){
	fa[x]=last;
	d[x]=d[last]+1;
	siz[x]=1;
	int cur=s.h[x],pus=-1;
	yyy tmp;
	while(cur!=-1){
		tmp=s.f[cur];
		if(tmp.to!=last){
			dfs1(tmp.to,x);
			siz[x]+=siz[tmp.to];
			if(pus<siz[tmp.to])pus=siz[tmp.to],son[x]=tmp.to;
		}
		cur=tmp.z;
	}
}
inline void dfs2(int x,int last){
	top[x]=last;
	id[x]=++idea;
	if(!son[x]) return;
	dfs2(son[x],last);
	int cur=s.h[x];
	yyy tmp;
	while(cur!=-1){
		tmp=s.f[cur];
		if(tmp.to!=fa[x]&&tmp.to!=son[x]) dfs2(tmp.to,tmp.to);
		cur=tmp.z;
	}
}
inline void swap(int &x,int &y){x^=y,y^=x,x^=y;}
inline void get1(int x){get(id[x],id[x]+siz[x]-1,1,1,n,1);}
inline void get2(int x,int y){
	while(top[x]!=top[y]) {
		if(d[top[x]]<d[top[y]]) swap(x,y);
		get(id[top[x]],id[x],-1,1,n,1);
		x=fa[top[x]];
	}
	if(d[x]>d[y]) swap(x,y);
	get(id[x],id[y],-1,1,n,1);
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
inline int find1(int x){return find(id[x],1,n,1);}
int main(){
	memset(s.h,-1,sizeof(s.h));
	register int i;
	read(n);
	for(i=1;i<n;i++) read(x),read(y),s.add(x,y),s.add(y,x);
	dfs1(1,0);
	dfs2(1,1);
	read(m);
	for(i=1;i<=m;i++){
		read(x);read(y);
		if(x==1)get1(y);
		else if(x==2)get2(y,1);
		else print(find1(y)),putchar('\n');
	}
}