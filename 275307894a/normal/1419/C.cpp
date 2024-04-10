#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,x,y,z,a[100039],t,flag[100039],flags,ans;
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		flags=0;
		for(i=1;i<=n;i++) scanf("%d",&a[i]),flag[i]=(a[i]==m?1:0);
		for(i=1;i<=n;i++) flags+=flag[i];
		if(flags==n) printf("0\n");
		else if(flags) printf("1\n");
		else{
			ans=0;
			for(i=1;i<=n;i++) ans+=a[i];
			if(ans==n*m) printf("1\n");
			else printf("2\n");
		}
	}
}