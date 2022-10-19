#include<cstdio>
using namespace std;
int n,m,k,x,y,z,siz[100039],d[100039];
double ans,tot,pus,q[100039];
struct yyy{int to,z;};
struct ljb{
	int head,h[100039];
	yyy f[200039];
	inline void add(int x,int y){
		f[++head]=(yyy){y,h[x]};
		h[x]=head;
	}
}s;
inline void dfs(int x,int last){
	yyy tmp;d[x]=d[last]+1;
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];if(tmp.to!=last)siz[x]++;
	}
	if(!siz[x])ans+=(d[x]-1)*q[x];
	for(int cur=s.h[x];cur;cur=tmp.z){
		tmp=s.f[cur];
		if(tmp.to!=last) q[tmp.to]=q[x]/siz[x],dfs(tmp.to,x);
	}
}
int main(){
	register int i;
	//freopen("room.in","r",stdin);
	//freopen("room.out","w",stdout);
	scanf("%d",&n);
	for(i=1;i<n;i++) scanf("%d%d",&x,&y),s.add(x,y),s.add(y,x);
	q[1]=1;dfs(1,0);
	printf("%.12lf\n",ans);
}