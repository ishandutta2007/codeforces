#include<cstdio>
#include<algorithm>
#include<functional>
#define inf (1LL<<50)
#define N 100100
using namespace std;
int d[N],x[N],pos[2][N],sz[2];
long long to[2][N],pto[2][N];
bool can[N];
int main(){
	int n,ans=-1;
	scanf("%d",&n);
	for(int i=0;i<=n+1;i++) scanf("%d",&x[i]);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]),d[i]<<=1;
	sz[0]=1;
	pos[0][0]=x[0];
	to[0][0]=inf;
	for(int i=1;i<=n;i++){
		int p=upper_bound(to[0],to[0]+sz[0],x[i],greater<int>())-to[0]-1;
		if(d[i]<=(x[i]-pos[0][p])) continue;
		can[i]=true;
		pto[0][i]=x[i]+(d[i]-(x[i]-pos[0][p]));
		while(pto[0][i]>=to[0][sz[0]-1]) sz[0]--;
		to[0][sz[0]]=pto[0][i];
		pos[0][sz[0]]=x[i];
		sz[0]++;
	}
	if(sz[0]>=2&&to[0][1]>=x[n+1]) ans=0;
	sz[1]=1;
	pos[1][0]=x[n+1];
	to[1][0]=-inf;
	for(int i=n;i>=1;i--){
		if(can[i]){
			int p=upper_bound(to[1],to[1]+sz[1],pto[0][i])-to[1]-1;
			int tmp=pos[1][p]-x[i];
			if(ans==-1||tmp<ans) ans=tmp;
		}
		int p=upper_bound(to[1],to[1]+sz[1],x[i])-to[1]-1;
		if(d[i]<=(pos[1][p]-x[i])) continue;
		pto[1][i]=x[i]-(d[i]-(pos[1][p]-x[i]));
		while(pto[1][i]<=to[1][sz[1]-1]) sz[1]--;
		to[1][sz[1]]=pto[1][i];
		pos[1][sz[1]]=x[i];
		sz[1]++;
	}
	if(ans==-1||pos[1][sz[1]-1]-x[0]<ans) ans=pos[1][sz[1]-1]-x[0];
	printf("%g\n",ans*0.5);
	return 0;
}