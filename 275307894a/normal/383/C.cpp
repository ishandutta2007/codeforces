#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k,x,y,z,sx,tot,a[200039],f[2][200039],dfn[200039],end[200039],top[200039];
struct yyy{int to,z;};
struct ljb{
	int head,h[200039];
	yyy f[400039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void dfs(int x,int last,int t){
	top[x]=t;dfn[x]=++tot;
	int cur=s.h[x];
	yyy tmp;
	while(cur!=-1){
		tmp=s.f[cur];
		if(tmp.to!=last) dfs(tmp.to,x,t^1);
		cur=tmp.z;
	}
	end[x]=tot;
}
inline void get(int x,int y,int num){while(x<=n) f[num][x]+=y,x+=x&-x;}
inline int find(int x,int num){
	int ans=0;
	while(x) ans+=f[num][x],x-=x&-x;
	return ans;
}
inline void read(int &x){
	char s=getchar();x=0;
	while(s<'0'||s>'9') s=getchar();
	while(s>='0'&&s<='9') x=(x<<3)+(x<<1)+(s^48),s=getchar();
}
int main(){
	memset(s.h,-1,sizeof(s.h));
	register int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) read(a[i]);
	for(i=1;i<n;i++) read(x),read(y),s.add(x,y),s.add(y,x);
	dfs(1,0,1);
	for(i=1;i<=m;i++){
		read(sx);
		if(sx==1){
			read(x);read(y);
			get(dfn[x],y,top[x]);
			get(end[x]+1,-y,top[x]);
		}
		else{
			read(x);
			printf("%d\n",a[x]+find(dfn[x],top[x])-find(dfn[x],top[x]^1));
		}
	}
}