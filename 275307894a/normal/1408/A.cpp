#include<cstdio>
using namespace std;
int n,m,k,x,y,z,t,a[100039],b[1039],c[1039],s[1039];
int main(){
	register int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++) scanf("%d",&c[i]);
		s[1]=a[1];
		for(i=2;i<n;i++){
			if(a[i]!=s[i-1]) s[i]=a[i];
			else if(b[i]!=s[i-1])s[i]=b[i];
			else s[i]=c[i];
		}
		if(a[n]!=s[n-1]&&a[n]!=s[1]) s[n]=a[n];
		else if(b[n]!=s[n-1]&&b[n]!=s[1]) s[n]=b[n];
		else s[n]=c[n];
		for(i=1;i<=n;i++) printf("%d ",s[i]);
		printf("\n");
	}
}