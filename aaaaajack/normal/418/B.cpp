#include<cstdio>
#include<cstring>
#include<algorithm>
#define N (1<<20)
#define M 110
using namespace std;
long long dp[N];
struct frd{
	int	x;
	int k;
	int s;
	frd(){x=k=s=0;}
	bool operator<(frd rhs)const{return k<rhs.k;}
} q[M];
int main(){
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	int n,m,b,i,j,l;
	long long ans=-1;
	scanf("%d%d%d",&n,&m,&b);
	for(l=0;l<n;l++){
		scanf("%d%d%d",&q[l].x,&q[l].k,&i);
		while(i--){
			scanf("%d",&j);
			q[l].s|=1<<(j-1);
		}
	}
	sort(q,q+n);
	for(i=0;i<n;i++){
		for(j=0;j<(1<<m);j++){
			if(dp[j]==-1) continue;
			else if(dp[j|q[i].s]==-1 || dp[j]+q[i].x<dp[j|q[i].s]) dp[j|q[i].s]=dp[j]+q[i].x;
		}
		if(dp[(1<<m)-1]>=0){
			if(ans==-1 || dp[(1<<m)-1]+1LL*b*q[i].k<ans) ans=dp[(1<<m)-1]+1LL*b*q[i].k;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}