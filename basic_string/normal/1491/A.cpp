#include<bits/stdc++.h>
using namespace std;
int a[100009];
int main(){
	int T,n,i,j,k,s=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
	while(k--){
		scanf("%d%d",&i,&j);
		if(i==1)s-=a[j],a[j]^=1,s+=a[j];
		else if(j>s)puts("0");
		else puts("1");
	}
	return 0;
}