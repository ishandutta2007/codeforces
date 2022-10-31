#include<cstdio>
using namespace std;
int main(){
	int n,k,l,r,sk,sa;
	scanf("%d%d%d%d%d%d",&n,&k,&l,&r,&sa,&sk);
	int i;
	for(i=0;i<n;i++){
		if(i<sk%k) printf("%d",sk/k+1);
		else if(i<k) printf("%d",sk/k);
		else if(i<k+(sa-sk)%(n-k)) printf("%d",(sa-sk)/(n-k)+1);
		else printf("%d",(sa-sk)/(n-k));
		if(i==n-1) printf("\n");
		else printf(" ");
	}
	return 0;
}