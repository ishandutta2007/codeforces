#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	int piv,x,sm=0;
	int tmp,dif;
	bool dir=false,df=false;
	scanf("%d%d",&n,&k);
	printf("?");
	for(int i=1;i<=k;i++){
		printf(" %d",i);
	}
	puts("");
	fflush(stdout);
	scanf("%d%d",&piv,&x);
	for(int i=1;i<=k;i++){
		if(i==piv) continue;
		printf("?");
		for(int j=1;j<=k+1;j++){
			if(j==i) continue;
			printf(" %d",j);
		}
		puts("");
		fflush(stdout);
		scanf("%d%d",&tmp,&dif);
		if(dif==x){
			sm++;
		}
		else if(dif>x){
			dir=true;
			df=true;
		}
		else{
			dir=false;
			df=true;
		}
	}
	if(!df){
		printf("?");
		for(int i=1;i<=k+1;i++){
			if(i==piv) continue;
			printf(" %d",i);
		}
		puts("");
		fflush(stdout);
		scanf("%d%d",&tmp,&dif);
		if(dif>x) dir=true;
		else dir=false;
	}
	if(dir) printf("! %d\n",k-sm);
	else printf("! %d\n",sm+1);
	return 0;
}