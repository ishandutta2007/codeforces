#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t,a[59],flag;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		flag=0;
		scanf("%d%d",&n,&x);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&y),flag|=a[n-i+1]+y>x?1:0;
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
}