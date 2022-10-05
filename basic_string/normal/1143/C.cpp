#include<bits/stdc++.h>
using namespace std;
int a[100009];
int main(){
	int n,i,j,k; 
	scanf("%d",&n),memset(a,1,sizeof a);
	for(i=1;i<=n;++i){
		scanf("%d%d",&j,&k);
		if(j==-1)j=0;
		if(!k){
			a[i]=a[j]=0;
		}
	}
	k=0;
	for(i=1;i<=n;++i)if(a[i])printf("%d ",i),k=1; 
	if(!k)puts("-1");
	return 0;
}