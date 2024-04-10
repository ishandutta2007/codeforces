#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int m,n,i;
	double pre=1,nxt,ans=0;
	scanf("%d%d",&m,&n);
	for(i=m;i>=1;i--){
		nxt=pre*pow(1.0*(i-1)/i,n);
		ans+=i*(pre-nxt);
		pre=nxt;
	}
	printf("%.8f\n",ans);
	return 0;
}