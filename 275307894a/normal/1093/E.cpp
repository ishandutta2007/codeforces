#include<cstdio>
using namespace std;
int n,m,k,x,y,z,sx,sy,a[200039],b[200039],p[200039],root[200039],tot,st[8000039],head;
struct yyy{int l,r,f;}f[40000039];
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline void gets(int x,int y,int l,int r,int &now){
	if(!now){
		if(head)now=st[head],head--;
		else now=++tot;
	}
	f[now].f+=y;
	if(l==r) return;
	int m=(l+r)>>1;
	if(x<=m) gets(x,y,l,m,f[now].l);
	else gets(x,y,m+1,r,f[now].r);
	if(!f[now].f) f[now].l=f[now].r=0,st[++head]=now,now=0;
}
inline void get(int x,int y,int z){
	while(x<=n){
		gets(y,z,1,n,root[x]);
		x+=x&-x;
	}
}
inline int finds(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y)return f[now].f;
	int m=(l+r)>>1,fs=0;
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
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),p[a[i]]=i;
	for(i=1;i<=n;i++) scanf("%d",&b[i]),b[i]=p[b[i]];
	for(i=1;i<=n;i++)get(i,b[i],1);
	for(i=1;i<=m;i++){
		scanf("%d",&z);
		if(z==1){
		    scanf("%d%d%d%d",&x,&y,&sx,&sy);
			printf("%d\n",find(sy,x,y)-find(sx-1,x,y));
		}
		else{
			scanf("%d%d",&x,&y);
			get(x,b[x],-1);get(y,b[y],-1);
			swap(b[x],b[y]);
			get(x,b[x],1),get(y,b[y],1);
		}
	}
}