#include<cstdio>
#define beg int cur=s.h[x]
#define end cur
#define go cur=tmp.z
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,f[539],k,x,y,z,d[50039],anss,dp[50039],siz[50039],ans,tot,pus,flag[50039];
struct stack{
	int sh,st[50039];
	inline void push(int x){st[++sh]=x;}
	inline int top(){return st[sh];}
	inline void clear(){sh=0;}
	inline void pop(){sh--;}
	inline int empty(){return sh?0:1;}
}g;
struct yyy{int to,w,z;};
struct ljb{
	int head,h[50039];
	yyy f[100039];
	inline void add(int x,int y,int z){
		f[++head]=(yyy){y,z,h[x]};
		h[x]=head;
	}
}s;
inline void dfs1(int x,int last){
	yyy tmp;dp[x]=0;siz[x]=1;
	for(beg;end;go){
		tmp=s.f[cur];
		if(tmp.to!=last&&!flag[tmp.to]) dfs1(tmp.to,x),dp[x]=max(dp[x],siz[tmp.to]),siz[x]+=siz[tmp.to];
	}
}
inline void dfs2(int x,int last,int len){
	yyy tmp;dp[x]=max(dp[x],len-siz[x]);
	if(dp[x]<ans)ans=dp[x],tot=x;
	for(beg;end;go){
		tmp=s.f[cur];
		if(tmp.to!=last&&!flag[tmp.to]) dfs2(tmp.to,x,len);
	}
}
inline void dfs3(int x,int last){
	register int i;yyy tmp;
	if(d[x]<=k) anss+=f[k-d[x]];
	for(beg;end;go){
		tmp=s.f[cur];
		if(tmp.to!=last&&!flag[tmp.to]) d[tmp.to]=d[x]+tmp.w,dfs3(tmp.to,x);
	}
}
inline void dfs4(int x,int last){
	if(d[x]<=k)f[d[x]]++,g.push(d[x]);
	yyy tmp;
	for(beg;end;go) {
		tmp=s.f[cur];
		if(tmp.to!=last&&!flag[tmp.to]) dfs4(tmp.to,x);
	}
}
inline void dfs(int x,int last){
	while(!g.empty())f[g.top()]=0,g.pop();
	f[0]=1;dfs1(x,last);
	yyy tmp;
	if(siz[x]==1) return;
	ans=1e9;tot=0;dfs2(x,last,siz[x]);
	x=tot;flag[last]=1;d[x]=0;
	for(beg;end;go){
		tmp=s.f[cur];
		if(!flag[tmp.to])d[tmp.to]=tmp.w,dfs3(tmp.to,x),dfs4(tmp.to,x);
	}
	for(beg;end;go){
		tmp=s.f[cur];if(!flag[tmp.to])dfs(tmp.to,x);
	}
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	register int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<n;i++)scanf("%d%d",&x,&y),s.add(x,y,1),s.add(y,x,1);
	dfs(1,0);
	printf("%d\n",anss);
}