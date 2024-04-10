#include<cstdio>
using namespace std;
int main(){
	int m,n,a[10]={0},t[10],i;
	scanf("%d%d",&m,&n);
	while(m--){
		for(i=0;i<n;i++) scanf("%d",&t[i]);
		a[0]+=t[0];
		for(i=1;i<n;i++){
			if(a[i]>a[i-1]) a[i]+=t[i];
			else a[i]=a[i-1]+t[i];
		}
		if(m) printf("%d ",a[n-1]);
		else printf("%d\n",a[n-1]);
	}
	return 0;
}