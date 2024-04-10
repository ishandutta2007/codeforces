#include<bits/stdc++.h>
using namespace std;
char s[100111],t[100111];
int n,i,j,k,res;
int main(){
	scanf("%d",&n);
	scanf("%s %s",s,t);
	for(i=0;s[i]==t[i];i++);
	for(j=n-1;s[j]==t[j];j--);
	for(k=i;k<j&&s[k+1]==t[k];k++);
	res+=(k==j);
	for(k=i;k<j&&s[k]==t[k+1];k++);
	res+=(k==j);
	printf("%d\n",res);
	return 0;
}