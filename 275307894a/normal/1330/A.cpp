#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[139],ans,tot,pus,f[139],t,m,flag;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		flag=0;ans=0;
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		a[0]=a[1]-1;
		for(i=1;i<=n;i++){
			if(a[i]!=a[i-1]) ans++;
			if(ans+m<a[i]){printf("%d\n",ans-1+m);flag=1;break;}
		}
		if(!flag) printf("%d\n",ans+m);
	}
}