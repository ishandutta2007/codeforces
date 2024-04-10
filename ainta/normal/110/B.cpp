#include<stdio.h>
int w[26],D[200000],i,n,j,t;
int O(int a){
	t=a;
	while(t>0){if(t%10!=4&&t%10!=7)break;t/=10;}
	if(t==0)return 1;
	return 0;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=0;j<26;j++){
			if(w[j]==0) break;
			if(O(i-w[j])) break;}
		D[i]=j;
		w[j]=i;}
	for(i=1;i<=n;i++)printf("%c",D[i]+'a');
}