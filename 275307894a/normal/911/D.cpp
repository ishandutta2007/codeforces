#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[1539],ans,flag;
int main(){
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++) if(a[i]>a[j]) flag^=1;
	}scanf("%d",&m);
	while(m--){
		scanf("%d%d",&x,&y);ans=(y-x+1);
		ans=ans*(ans-1)/2;
		if(ans&1) flag^=1;
		printf("%s\n",flag?"odd":"even");
	}
}