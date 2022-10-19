#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z;
long long siz[200039],dp[200039],ans,a[200039];
struct yyy{int to,z;};
struct ljb{
	int head,h[200039];
	yyy f[400039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void dfs1(int x,int last){
	siz[x]=a[x];
	int cur=s.h[x];
	yyy tmp;
	while(cur!=-1){
		tmp=s.f[cur];
		if(tmp.to!=last) dfs1(tmp.to,x),siz[x]+=siz[tmp.to],dp[x]+=dp[tmp.to]+siz[tmp.to];
		cur=tmp.z;
	}
}
inline void dfs2(int x,int last){
	int cur=s.h[x];
	yyy tmp;
	while(cur!=-1){
		tmp=s.f[cur];
		if(tmp.to!=last){
			dp[tmp.to]=dp[x]-siz[tmp.to]+(siz[1]-siz[tmp.to]);
			dfs2(tmp.to,x);
		}
		cur=tmp.z;
	}
}
int main(){
//	freopen("1.in","r",stdin);
	memset(s.h,-1,sizeof(s.h));
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);
	dfs1(1,0);dfs2(1,0);
	for(i=1;i<=n;i++) ans=max(ans,dp[i]);
	printf("%lld\n",ans);
}