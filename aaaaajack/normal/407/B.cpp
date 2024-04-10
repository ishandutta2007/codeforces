#include<cstdio>
#define Q 1000000007
using namespace std;
int main(){
	int a[2000],p[2000],n,i;
	a[0]=0;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&p[i]);
	for(i=1;i<=n;i++){
		a[i]=((a[i-1]<<1)-a[p[i-1]-1]+2)%Q;
		if(a[i]<0) a[i]+=Q;
	}
	printf("%d\n",a[n]);
	return 0;
}