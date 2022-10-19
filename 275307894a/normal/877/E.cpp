#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,x,y,z,head,a[200039],s[200039],h[200039],f[800039],sum[800039],dfn[200039],now,dh,tots[200039],nows[200039];
char _s;
struct yyy{
	int to,z;
}fs[200039];
inline void add(int x,int y){
	fs[++head]=(yyy){y,h[x]};
	h[x]=head;
}
inline void dfs(int x){
	dfn[++now]=x;
	tots[x]=now;
//	printf("%d\n",x);
	int cur=h[x],nows=now,nowsans;
	yyy tmp;
	while(cur!=-1){
		tmp=fs[cur];
		nowsans=now+1;dfs(tmp.to);s[nows]+=s[nowsans];
		cur=tmp.z;
	}
	s[nows]++;
	return;
}
inline void jianshu(int l,int r,int now){
	if(l==r){sum[now]=a[dfn[l]];return;}
	int m=(l+r)>>1;
	jianshu(l,m,now<<1);
	jianshu(m+1,r,now<<1|1);
	sum[now]=sum[now<<1]+sum[now<<1|1];
}
inline void push(int l,int r,int now){
	int m=(l+r)>>1;
	f[now<<1]^=1;
	f[now<<1|1]^=1;
	//printf("%d\n",now);
	sum[now<<1]=m-l+1-sum[now<<1];
	sum[now<<1|1]=r-m-sum[now<<1|1];
	f[now]=0;
}
inline int find(int l,int r,int now){
	if(x<=l&&r<=y) return sum[now];
	int m=(l+r)>>1,fs=0;
	if(f[now])push(l,r,now);
	if(x<=m) fs+=find(l,m,now<<1);
	if(y>m) fs+=find(m+1,r,now<<1|1);
	return fs;
}
inline void get(int l,int r,int now){
	if(x<=l&&r<=y) {f[now]^=1;sum[now]=r-l+1-sum[now];return;}
	int m=(l+r)>>1;
	if(f[now])push(l,r,now);
	if(x<=m) get(l,m,now<<1);
	if(y>m) get(m+1,r,now<<1|1);
	sum[now]=sum[now<<1]+sum[now<<1|1]; 
}
int main(){
	memset(h,-1,sizeof(h));
	register int i;
	scanf("%d",&n);
	for(i=2;i<=n;i++) scanf("%d",&x),add(x,i);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	//putchar('\n');
	//for(i=1;i<=n;i++) printf("%d\n",s[i]);
	jianshu(1,n,1);
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		_s=getchar();
		while(_s<'a'||_s>'z') _s=getchar();
		if(_s=='g'){
			_s=getchar();_s=getchar();
			scanf("%d",&x);
			x=tots[x];
			y=x+s[x]-1;
			printf("%d\n",find(1,n,1));
		}
		else{
			_s=getchar();_s=getchar();
			scanf("%d",&x);
			x=tots[x];
			y=x+s[x]-1;
			get(1,n,1);
		}
	}
}