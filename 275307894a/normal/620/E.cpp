#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,x,y,z,dh,st[400039],bg[400039],tot,op;
long long f[2000039],flag[2000039],a[400039],ans,dfn[400039];
struct yyy{int to,z;};
struct ljb{
	int head,h[400039];
	yyy f[800039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void dfs(int x,int last){
	st[x]=++dh;
	dfn[dh]=x;
	yyy tmp;
	for(int cur=s.h[x];~cur;cur=tmp.z){
		tmp=s.f[cur];
		if(tmp.to!=last) dfs(tmp.to,x);
	}
	bg[x]=dh;
}
inline void jianshu(int l,int r,int now){
	if(l==r){
		f[now]=dfn[l];
		return;
	}
	int m=(l+r)>>1;
	jianshu(l,m,now<<1);jianshu(m+1,r,now<<1|1);
	f[now]=f[now<<1]|f[now<<1|1];
}
inline void push(int now){flag[now<<1]=flag[now<<1|1]=f[now<<1]=f[now<<1|1]=flag[now];flag[now]=0;}
inline void get(int x,int y,int z,int l,int r,int now){
	if(x<=l&&r<=y){
		f[now]=flag[now]=1ll<<z;
		return;
	}
	if(flag[now])push(now);
	int m=(l+r)>>1;
	if(x<=m)get(x,y,z,l,m,now<<1);
	if(y>m) get(x,y,z,m+1,r,now<<1|1);
	f[now]=f[now<<1]|f[now<<1|1];
}
inline long long find(int x,int y,int l,int r,int now){
	if(x<=l&&r<=y) return f[now];
	int m=(l+r)>>1;
	long long fs=0;
	if(flag[now])push(now);
	if(x<=m) fs|=find(x,y,l,m,now<<1);
	if(y>m) fs|=find(x,y,m+1,r,now<<1|1);
	return fs;
}
int main(){
	memset(s.h,-1,sizeof(s.h));
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]=1ll<<a[i];
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);
	dfs(1,0);
	for(i=1;i<=n;i++) dfn[i]=a[dfn[i]];
	jianshu(1,n,1);
	for(i=1;i<=m;i++){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			get(st[x],bg[x],y,1,n,1);	
		}
		else{
			scanf("%d",&x);
			ans=find(st[x],bg[x],1,n,1);
			tot=0;
			while(ans)tot++,ans-=ans&-ans;
			printf("%d\n",tot);
		}
	}
}