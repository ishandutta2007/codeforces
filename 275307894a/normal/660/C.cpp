#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int n,m,k,a[300039],q[300039],x,y,z,l,r=1,mid,tot,ans;
int main(){
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&a[i]),a[i]^=1,q[i]=q[i-1]+a[i];
	for(i=1;i<=n;i++){
		while(q[i]-q[r-1]>m) r++;
		ans=max(ans,i-r+1);
	}
	r=1;
	for(i=1;i<=n;i++){
		while(q[i]-q[r-1]>m) r++;
		if(i-r+1==ans){
			for(j=r;j<=i;j++) a[j]=0;
			printf("%d\n",ans);
			for(j=1;j<=n;j++){
				printf("%d",a[j]^1);
				if(j!=n) printf(" ");
			}
			return 0;
		}
	}
}