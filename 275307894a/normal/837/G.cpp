#include<cstdio>
#define mod 1000000000
using namespace std;
int n,m,k,x,y,z,sx,sy,sz,root[100039],tot;
long long last;
struct tree{int l,r,f;long long sum;}f[10000039];
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(long long x){
	if(x>9) print(x/10);
	putchar(x%10+48);
}
inline void xj(int &now){f[++tot]=f[now];now=tot;}
inline void get(int x,int y,int z,int l,int r,int &now){
	xj(now);f[now].f+=y;f[now].sum+=z;
	if(l==r)return;
	int m=(l+r)>>1;
	if(x<=m) get(x,y,z,l,m,f[now].l);
	else get(x,y,z,m+1,r,f[now].r);
}
inline long long find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f[now].sum+(long long)f[now].f*y;
	int m=(l+r)>>1;
	long long fs=0;
	if(x<=m&&f[now].l)fs+=find(x,y,l,m,f[now].l);
	if(y>m&&f[now].r) fs+=find(x,y,m+1,r,f[now].r);
	return fs;
}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	read(n);
	for(i=1;i<=n;i++){
		root[i]=root[i-1];
		read(x);read(y);read(z);read(sx);read(sy);read(sz);
		get(0,0,z,0,1e9,root[i]);
		get(x+1,sx,sy-z,0,1e9,root[i]);
		get(y+1,-sx,sz-sy,0,1e9,root[i]);
	}
	read(m);
	for(i=1;i<=m;i++){
		read(x);read(y);read(z);
		z=(z+last)%mod;
		last=find(0,z,0,1e9,root[y])-find(0,z,0,1e9,root[x-1]);
		print(last);putchar('\n');
	}
}