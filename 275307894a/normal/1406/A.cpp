#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,x,y,z,t,a[100039],flag[139],ans;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(i=0;i<=100;i++) flag[i]=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]),flag[a[i]]++;
		for(i=1;i<=100;i++){
			if(!flag[i-1]) break;
			flag[i-1]--;
			for(j=0;j<=100;j++) if(!flag[j]){ans=max(ans,i+j);break;}
		}
		printf("%d\n",ans);
	}
}