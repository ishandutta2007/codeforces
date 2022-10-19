#include<cstdio>
#define min(a,b) ((a)<(b )?(a):(b))
using namespace std;
int n,m,k,x,y,z,t,flag[139],ans,w[139];
int main(){
	int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=100;i++) flag[i]=w[i]=0;ans=0;
		for(i=1;i<=n;i++){
			scanf("%d",&x);
			flag[x]++;
		}
		while(m--) scanf("%d",&x),w[x]++;
		for(i=1;i<=100;i++) ans+=min(flag[i],w[i]);
		printf("%d\n",ans);
	}
}