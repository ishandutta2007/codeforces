#include<cstdio>
#define N 100039
#define mod 1000000007
#define I inline
using namespace std;
int n,m,k,x,y,z,f[N],cnt,flag[N],pr[N],ph,w=70,now;
I void insert(int x){
	for(int i=ph;~i;i--){
		if(x&(1<<i)){
			if(!f[i]){f[i]=x;cnt++;break;}
			x^=f[i];
		}
	}
}
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;scanf("%d",&n);
	for(i=2;i<=w;i++){
		if(!flag[i]) pr[++ph]=i;
		for(j=1;j<=ph&&pr[j]*i<=w;j++){
			flag[pr[j]*i]=1;
			if(i%pr[j]==0) break;
		}
	}
	for(i=1;i<=n;i++){
		scanf("%d",&x);now=0;
		for(j=1;j<=ph;j++){now<<=1;while(x%pr[j]==0) x/=pr[j],now^=1;}insert(now);
	}
	now=1;for(i=1;i<=n-cnt;i++) now=now*2%mod;printf("%d\n",(now-1+mod)%mod);
}