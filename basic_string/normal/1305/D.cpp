#include<bits/stdc++.h>
using namespace std;
int d[1009];
bool f[1009],e[1009][1009];
int main(){
	int n,i,j,k,l,t;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		e[j][k]=e[k][j]=1;
		++d[j],++d[k];
	}
	for(t=n/2;t;--t){
		for(i=1;i<=n;++i){
			if(d[i]==1&&!f[i]){
				j=i,f[i]=1;break;
			}
		}
		for(i=1;i<=n;++i){
			if(d[i]==1&&!f[i]){
				k=i,f[i]=1;break;
			}
		}
		printf("? %d %d\n",j,k),fflush(stdout);
		scanf("%d",&l);
		if(j==l){
			printf("! %d\n",j),fflush(stdout);
			return 0;
		}
		if(k==l){
			printf("! %d\n",k),fflush(stdout);
			return 0;
		}
		for(i=1;i<=n;++i){
			if(e[j][i])--d[i];
			if(e[k][i])--d[i];
		}
	}
	for(i=1;i<=n;++i){
		if(!f[i]){
			printf("! %d\n",i),fflush(stdout);
			break;
		}
	}
	return 0;
}//