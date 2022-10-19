#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t,flag,a[1000039];
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		flag=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=n-1;i;i--)  if(a[i]<=a[i+1]) flag=1;
		if(!flag) printf("No\n");
		else printf("Yes\n");
	}
}