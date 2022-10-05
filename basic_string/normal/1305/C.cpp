#include<bits/stdc++.h>
using namespace std;
int a[4009];
int main(){
	int n,m,i,j,s=1;
	scanf("%d%d",&n,&m);
	if(n>4000){
		puts("0");
		return 0;
	}
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i){
		for(j=i+1;j<=n;++j){
			if(a[i]>a[j])s=s*1ll*(a[i]-a[j])%m;
			else s=s*1ll*(a[j]-a[i])%m;
		}
	}
	printf("%d",s);
	return 0;
}//