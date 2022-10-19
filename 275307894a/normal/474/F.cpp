#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,a[100039],root[100039],tot,sum[400039],ans;
struct tree{int l,r,f;}f[10000039];
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
inline void print(int x){
	if(x>9) print(x/10);
	putchar(x%10+48);
}
inline void jianshu(int l,int r,int now){
	if(l==r){sum[now]=a[l];return;}
	int m=(l+r)>>1;
	jianshu(l,m,now<<1);jianshu(m+1,r,now<<1|1);
	sum[now]=__gcd(sum[now<<1],sum[now<<1|1]);
}
inline int find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return  sum[now];
	int m=(l+r)>>1;
	if(x<=m&&y<=m) return find(x,y,l,m,now<<1);
	if(x>m&&y>m) return find(x,y,m+1,r,now<<1|1);
	return __gcd(find(x,y,l,m,now<<1),find(x,y,m+1,r,now<<1|1));
}
inline void xj(int &now){f[++tot]=f[now];now=tot;}
inline void get(int x,int l,int r,int &now){
	xj(now);f[now].f++;
	if(l==r)return;
	int m=(l+r)>>1;
	if(x<=m) get(x,l,m,f[now].l);
	else get(x,m+1,r,f[now].r);
}
inline int finds(int x,int l,int r,int now){
	if(l==r) return f[now].f;
	int m=(l+r)>>1;
	if(x<=m&&f[now].l) return finds(x,l,m,f[now].l);
	if(x>m&&f[now].r) return finds(x,m+1,r,f[now].r);
	return 0;
}
int main(){
	register int i;
	read(n);
	for(i=1;i<=n;i++)read(a[i]);
	jianshu(1,n,1);
	scanf("%d",&m);
	for(i=1;i<=n;i++){
		root[i]=root[i-1];
		get(a[i],0,1e9,root[i]);
	}
	for(i=1;i<=m;i++){
		read(x);read(y);
		ans=find(x,y,1,n,1);
		print(y-x+1-(finds(ans,0,1e9,root[y])-finds(ans,0,1e9,root[x-1])));putchar('\n');
	}
}