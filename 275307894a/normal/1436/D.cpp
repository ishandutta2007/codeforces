#include<cstdio>
#include<cmath>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,siz[200039];
long long d[200039],ans,a[200039];
struct yyy{int to,z;};
struct ljb{
	int head,h[200039];
	yyy f[200039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void dfs(int x){
	yyy tmp;d[x]+=a[x];
	if(!s.h[x]) siz[x]=1;
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];
		dfs(tmp.to);
		siz[x]+=siz[tmp.to];
		d[x]+=d[tmp.to];
	}
	ans=max(ans,((d[x]+siz[x]-1)/siz[x]));
}
int main(){
	register int i;
	scanf("%d",&n);
	for(i=2;i<=n;i++) scanf("%d",&x),s.add(x,i);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%lld\n",ans);
}