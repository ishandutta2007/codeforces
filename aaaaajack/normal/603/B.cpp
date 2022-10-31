#include<cstdio>
#define Q 1000000007
using namespace std;
int main(){
	int p,k,ans=1;
	scanf("%d%d",&p,&k);
	if(k==0){
		for(int i=0;i<p-1;i++){
			ans=1LL*ans*p%Q;
		}
	}
	else{
		int c=1,x=k;
		while(x!=1){
			c++;
			x=1LL*x*k%p;
		}
		if(c==1) ans=1LL*ans*p%Q;
		for(int i=0;i<(p-1)/c;i++) ans=1LL*ans*p%Q;
	}
	printf("%d\n",ans);
	return 0;
}