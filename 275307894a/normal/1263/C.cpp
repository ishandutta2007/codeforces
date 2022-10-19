#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n,x,y,ans,a[200039],tot;
int main(){
	register int i,j;
	scanf("%d",&n);
	while(n--){
		ans=y=x=tot=0;
		scanf("%d",&t);
		for(i=0;i*i<=t;i++) a[++ans]=i;
		a[++ans]=t;
		for(i=2;i*i<=t;i++){
			y=t/i;
			if(y!=x) a[++ans]=y;
			x=y;
		}
		sort(a+1,a+ans+1);
		tot=ans;
		for(i=2;i<=tot;i++){
			if(a[i]==a[i-1]) ans--;
		}
		printf("%d\n",ans);
		printf("%d",a[1]);
		for(i=2;i<=tot;i++){
			if(a[i]!=a[i-1])printf(" %d",a[i]);
		}
		printf("\n");
	}
}