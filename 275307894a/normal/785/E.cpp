#include<cstdio>
using namespace std;
int n,m,k,x,y,root[200039],h[200039],a[200039],tot;
long long ans;
struct tree{int l,r, f;}f[30000039];
inline void gets(int x,int y,int l,int r,int &now){
	if(!now) now=++tot;f[now].f+=y;
	if(l==r) return;
	int m=(l+r)>>1;
	if(x<=m) gets(x,y,l,m,f[now].l);
	else gets(x,y,m+1,r,f[now].r);
}
inline void get (int x,int y,int z){
	while(x<=n){
		gets(y,z,1,n,root[x]);
		x+=x&-x;
	}
}
inline int finds(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f[now].f;
	int m=l+r>>1,fs=0;
	if(x<=m&&f[now].l) fs+=finds(x,y,l,m,f[now].l);
	if(y>m&&f[now].r) fs+=finds(x,y,m+1,r,f[now].r);
	return fs;
}
inline int find(int x,int y,int z){
	int ans=0;
	while(x){
		ans+=finds(y,z,1,n,root[x]);
		x-=x&-x;
	}
	return ans;
}
inline void swap(int &x,int &y){x^=y^=x^=y;}
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)get(i,i,1),a[i]=i;
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(x!=y){
			if(x>y) swap(x,y);
			if(a[x]>a[y]) ans--;
			else ans++;
			ans+=y-x-1-(find(y-1,1,a[x])-find(x,1,a[x]))*2+y-x-1-(find(y-1,a[y],n)-find(x,a[y],n))*2;
			get(x,a[x],-1);get(y,a[y],-1);
			swap(a[x],a[y]);
			get(x,a[x],1);get(y,a[y],1);
		}
		printf("%lld\n",ans);
	}
}