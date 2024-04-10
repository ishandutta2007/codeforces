#include<cstdio>
using namespace std;
int n,m,k,x,y,z,a[100039],ans=1,now,now1,now2,net[100039],f[100039];
int main(){
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=0;i<=n;i++) f[a[i]]=n+1;
	for(i=n;i>=0;i--){
		net[i]=f[a[i]];
		f[a[i]]=i;
	}
	for(i=1;i<=n;i++){
		if(a[now1]!=a[i]&&a[now2]!=a[i]){
			now++;
			if(net[now1]<net[now2]) now2=i;
			else now1=i;
		}
		else if(a[now1]==a[i]) now1=i;
		else if(a[now2]==a[i]) now2=i;
	}
	printf("%d\n",now);
}