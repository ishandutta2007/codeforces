#include<bits/stdc++.h>
using namespace std;
int n,m,rem;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(x<m-rem){rem+=x;printf("0 ");continue;}
		x-=m-rem;
		printf("%d ",x/m+1);
		rem=x%m;
	}
	return 0;
}