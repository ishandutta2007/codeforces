#include<bits/stdc++.h>
using namespace std;
int a[109],b[109],c[109],d[109];
int main(){
	int T,n,i;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",a+i); 
		for(i=1;i<=n;++i)scanf("%d",b+i); 
		for(i=1;i<=n;++i)scanf("%d",c+i); 
		d[1]=a[1];
		for(i=2;i<n;++i){
			if(d[i-1]!=a[i])d[i]=a[i];
			else if(d[i-1]!=b[i])d[i]=b[i];
			else d[i]=c[i];
		}
		if(d[n-1]!=a[n]&&d[1]!=a[n])d[n]=a[n];
		else if(d[n-1]!=b[n]&&d[1]!=b[n])d[n]=b[n];
		else d[n]=c[n];
		for(i=1;i<=n;++i)printf("%d ",d[i]);
		putchar(10);
}
	return 0;
}/////////////////