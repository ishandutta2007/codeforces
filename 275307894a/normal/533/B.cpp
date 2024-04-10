#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,head,h[200039],a[200039];
long long dp[200039][2];
struct yyy{
	int to,z;
}f[400039];
inline void add(int x,int y){
	f[++head]=(yyy){y,h[x]};
	h[x]=head;
}
inline void dfs(int x,int last){
	int cur=h[x];
	long long now1,now2;
	yyy tmp;
	dp[x][1]=-1e15;
	while(cur!=-1){
		tmp=f[cur];
		if(tmp.to!=last){
			dfs(tmp.to,x);
			now1=dp[x][1],now2=dp[x][0];
			dp[x][1]=max(now2+dp[tmp.to][1],now1+dp[tmp.to][0]);
			dp[x][0]=max(now2+dp[tmp.to][0],now1+dp[tmp.to][1]);
		}
		cur=tmp.z;
	}
	now1=dp[x][1],now2=dp[x][0];
	dp[x][1]=max(now2+a[x],now1);
	//dp[x][0]=max(now2,now1+a[x]);
}
int main(){
	memset(h,-1,sizeof(h));
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&x,&a[i]);
		if(x!=-1) add(x,i),add(i,x);
	}
	dfs(1,0);
	printf("%lld\n",max(dp[1][0],dp[1][1]));
}