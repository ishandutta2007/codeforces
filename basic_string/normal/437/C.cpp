#include<bits/stdc++.h>
using namespace std;
int a[9999];
int main(){
	int n,m,i,j,s=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	while(m--){
		scanf("%d%d",&i,&j),s+=min(a[i],a[j]); 
	}printf("%d",s);
	return 0;
}