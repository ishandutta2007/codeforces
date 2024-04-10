#include<bits/stdc++.h>
using namespace std;
int n ,m,k,x,y,z,a[1000039],b[1000039];
int main(){
//	freopen("1.in","r",stdin);
	register int i;
	scanf("%d%d%d",&y,&x,&n);m=x+y;
	if((x<=1&&n)||(n>=m-1&&n)){printf("No\n");return 0;}
	if(!y){
		if(!n){
			printf("Yes\n");
			for(i=1;i<=x;i++) printf("1");printf("\n");
			for(i=1;i<=x;i++) printf("1");
		} 
		else printf("No");return 0;
	} 
	if(!n){
	    printf("Yes\n");
		for(i=1;i<=x;i++) printf("1");
		for(i=1;i<=y;i++) printf("0");printf("\n");
		for(i=1;i<=x;i++) printf("1");
		for(i=1;i<=y;i++) printf("0");return 0;
	}
	x--;
	a[1]=1;a[m-n]=1;x--;
	for(i=2;i<=m;i++){
		if(a[i]) continue;if(!x) break;
		a[i]=1,x--;
	}
	for(i=1;i<=m;i++)b[i]=a[i];
	b[m-n]=0;b[m]=1;
	printf("Yes\n");
	for(i=1;i<=m;i++) printf("%d",a[i]);printf("\n");
	for(i=1;i<=m;i++)printf("%d",b[i]);  
}