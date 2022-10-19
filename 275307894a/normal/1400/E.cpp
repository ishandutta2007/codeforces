#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int ans,tot,pus,a[50039],n;
inline int dfs(int x,int y){
	if(x==y){
		if(!a[x]) return 0;
		else return 1;
	}
	register int i,j;
	int maxn=1e9,now;
	for(i=x;i<=y;i++) maxn=min(maxn,a[i]);
	now=maxn;
	for(i=x;i<=y;i++) a[i]-=maxn;
	for(i=x;i<=y;i++){
		if(!a[i]) continue;
		for(j=i;j<=y;j++) if(!a[j+1]) break;
		now+=dfs(i,j);
		i=j;
	}
	return min(now,y-x+1);
}
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d\n",dfs(1,n));
}