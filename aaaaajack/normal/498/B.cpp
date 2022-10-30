#include<cstdio>
#include<cmath>
#include<cstring>
#define N 5010
using namespace std;
int main(){
	int n,T,t,i,j;
	double p,pre[N]={1},now[N]={},ans=0,tmp;
	scanf("%d%d",&n,&T);
	for(i=0;i<n;i++){
		scanf("%lf%d",&p,&t);
		p/=100;
		tmp=1;
		for(j=0;j<t;j++,tmp*=1-p) ans+=i*pre[T-j]*tmp;
		now[0]=0;
		if(1-p>1e-6) tmp/=1-p;
		for(j=1;j<=T;j++){
			now[j]=p*pre[j-1]+(1-p)*(now[j-1]-(j-1>=t?pre[j-1-t]*tmp:0));
			if(j>=t){
				now[j]-=p*tmp*pre[j-t];
				now[j]+=pre[j-t]*tmp;
			}
		}
		memcpy(pre,now,(T+1)*sizeof(double));
	}
	for(i=0;i<=T;i++) ans+=pre[i]*n;
	printf("%.8f\n",ans);
	return 0;
}