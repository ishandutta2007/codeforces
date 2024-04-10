#include<bits/stdc++.h>
using namespace std;
int a[109],b[109];
int main(){
	int T,n,i,j;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",a+i);
		for(i=1;i<=n;++i)scanf("%d",b+i);
		sort(a+1,a+n+1),sort(b+1,b+n+1);
		for(i=1;i<=n;++i)printf("%d ",a[i]);
		putchar(10);
		for(i=1;i<=n;++i)printf("%d ",b[i]);
		putchar(10); 
	}
	return 0;
}//