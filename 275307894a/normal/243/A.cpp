#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[100039],f[2000039],ans;
int main(){
//	freopen("1.in","r",stdin);
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++){
		if(!f[a[i]]) ans++,f[a[i]]=1;
		for(j=i-1;j;j--){
			if(a[j]==(a[i]|a[j])) break;
			a[j]|=a[i];
			if(!f[a[j]]) ans++,f[a[j]]=1;
		}
	}
	printf("%d\n",ans);
}