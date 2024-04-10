#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[100039],t;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++){
			if(i&1) printf("%d ",a[(i+1)/2]);
			else printf("%d ",a[n-i/2+1]);
		}
		putchar('\n');
	}
}