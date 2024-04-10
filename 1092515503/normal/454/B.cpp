#include<bits/stdc++.h>
using namespace std;
int n,num[100001],tot,sz;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
		tot+=(num[i-1]>num[i]);
		if(tot==1)sz++;
	}
	if(!tot){puts("0");return 0;}
	if(tot==1&&num[n]<=num[1])printf("%d\n",sz);
	else puts("-1");
	return 0;
}