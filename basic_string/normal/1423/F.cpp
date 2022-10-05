#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k,i,u,v,w=0,l=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;++i)scanf("%d%d",&u,&v),w=(w+u*1ll*v)%n,l+=v;
	if(l<n)puts("1");else if(l>n)puts("-1");
	else if((1ll+n)*n/2%n==w)puts("1");else puts("-1");
	return 0;
}