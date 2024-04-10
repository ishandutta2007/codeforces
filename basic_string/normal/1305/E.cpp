#include<bits/stdc++.h>
using namespace std;
int a[5009];
int main(){
	int n,m,p,i,j,k;
	scanf("%d%d",&n,&m);
	if(n&1)p=(n/2)*(n/2)-m;
	else p=(n/2)*(n/2-1)-m;
	if(p<0){
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;++i)a[i]=i;
	for(i=n;i;--i){
		if(!p)break;
		k=(i&1)?(i/2):(i/2-1);
		if(p>=k){
			p-=k,a[i]=77777777+i*30000;
			continue;
		}p=k-p;
		a[i]=a[i-1]+a[i-p-p];
		break;
	}
	for(i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}//