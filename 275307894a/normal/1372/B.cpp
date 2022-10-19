#include<cstdio>
#include<cmath>
using namespace std;
int t,n,k,ans,x,y;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		k=sqrt(n);
		ans=n-1;x=1;y=n-1;
		for(i=2;i<=k;i++) {
			if(n%i==0){
				if(ans>n-n/i){
					ans=n-n/i;
					x=n/i;y=n-n/i;
				}
				//printf("%d\n",n/i);
			}
		} 
		printf("%d %d\n",x,y);
	}
}