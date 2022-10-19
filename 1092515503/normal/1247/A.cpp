#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	if(n-m==-1){printf("%d9 %d0",n,m);return 0;}
	if(n==m){printf("%d0 %d1",n,m);return 0;}
	if(n==9&&m==1){puts("99 100");return 0;}
	puts("-1");
	return 0;
}